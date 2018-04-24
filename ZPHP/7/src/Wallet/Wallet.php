<?php

namespace Wallet;

use Events\ActivateWalletEvent;
use Events\CreateWalletEvent;
use Events\DeactivateWalletEvent;
use Events\DepositToWalletEvent;
use Events\WalletEvent;
use Events\WithdrawFromWalletEvent;
use EventSerializers\EventSerializer;
use Exceptions\ActiveWalletException;
use Exceptions\DifferentCurrenciesException;
use Exceptions\InactiveWalletException;
use Exceptions\NotEnoughMoneyInWalletException;
use Money\Money;
use Money\Currency;


class Wallet
{
    
    private $name;
    private $balance;
    private $isActive;
    private $isRecovering;
    private $events = array();
    
    /**
     * Wallet constructor.
     * @param string $name
     * @param string $currency
     * @param bool $isActive
     * @param bool|null $isRecovering
     * @throws ActiveWalletException
     */
    
    public function __construct(string $name,
                                string $currency,
                                bool $isActive = null,
                                bool $isRecovering = null)
    
    {
        $this->name = $name;
        $this->balance = new Money(0, new Currency($currency));
        
        if (!(is_null($isActive) && $isRecovering == true)) {
            if (is_null($isActive)) {
                array_push($this->events, new CreateWalletEvent($name, $currency));
                $this->activate('Create new Wallet');
                
            }
        }
    }
    
    public static function fromEvents(array $events): Wallet
    {
        if($events[0] instanceof CreateWalletEvent) {
            $wallet = new Wallet($events[0]->getName(), $events[0]->getCurrency(), false, true);
        }
        else{
            throw new \InvalidArgumentException();
        }
        for($i = 1 ; $i<count($events); $i++){
            if($events[$i] instanceof WalletEvent){
                $events[$i]->recreate($wallet);
            }
        }
        return $wallet;
    }
    
    public function deposit(Money $moneyToDeposit): void
    {
        if ($this->isActive) {
            if ($moneyToDeposit->isSameCurrency($this->balance)) {
                $this->balance = $this->balance->add($moneyToDeposit);
                if (!($this->isRecovering)) {
                    array_push($this->events, new DepositToWalletEvent($moneyToDeposit));
                }
            } else {
                throw new DifferentCurrenciesException();
            }
        } else {
            throw new InactiveWalletException();
        }
    }
    
    public function withdraw(Money $moneyToWithdraw): void
    {
        if ($this->isActive) {
            if ($moneyToWithdraw->isSameCurrency($this->balance)) {
                if ($moneyToWithdraw->lessThanOrEqual($this->balance)) {
                    $this->balance = $this->balance->subtract($moneyToWithdraw);
                    if (!($this->isRecovering)) {
                        array_push( $this->events, new WithdrawFromWalletEvent($moneyToWithdraw));
                    }
                } else {
                    throw new NotEnoughMoneyInWalletException();
                }
            } else {
                throw new DifferentCurrenciesException();
            }
        } else {
            throw new InactiveWalletException();
        }
    }
    
    public function deactivate(string $reason): void
    {
        if ($this->isActive) {
            $this->isActive = false;
            if (!($this->isRecovering)) {
                array_push($this->events, new DeactivateWalletEvent($reason));
            }
        } else {
            throw new InactiveWalletException('You cannot deactivate inactive wallet!');
        }
    }
    
    public function activate(string $reason): void
    {
        if ($this->isActive == false) {
            $this->isActive = true;
            if (!($this->isRecovering)) {
                array_push($this->events, new ActivateWalletEvent($reason));
            }
        } else {
            throw new ActiveWalletException('You cannot activate active wallet!');
        }
    }
    
    public function getBalance(): Money
    {
        return $this->balance;
    }
    
    public function changeRecoveringState(): void
    {
        $this->isRecovering = !($this->isRecovering);
    }
    
    public function getName(): string
    {
        return $this->name;
    }
    
    public function serialize(EventSerializer $serializer){
        $serializer->serialize($this->events);
        $this->events = array();
    }
}
