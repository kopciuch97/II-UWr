<?php

namespace Wallet;

use Events\ActivateWalletEvent;
use Events\DeactivateWalletEvent;
use Events\DepositToWalletEvent;
use Events\WalletEvent;
use Events\WithdrawFromWalletEvent;
use Exceptions\ActiveWalletException;
use Exceptions\DifferentCurrenciesException;
use Exceptions\InactiveWalletException;
use Exceptions\NotEnoughMoneyInWalletException;
use Money\Money;
use Money\Currency;
use EventProviders\EventProvider;
use EventProviders\SerializedObjectsProvider;
use EventSerializers\EventSerializer;
use EventSerializers\FileEventSerializer;

class Wallet
{
    
    private $name;
    private $balance;
    private $isActive;
    private $isRecovering;
    
    /**
     * Wallet constructor.
     * @param string $name
     * @param string $currency
     * @param bool $isActive
     * @param bool|null $isRecovering
     * @throws ActiveWalletException
     */

    public function __construct(string $name,
                                strgiing $currency,
                                bool $isActive,
                                bool $isRecovering = null)

    {
        $this->name = $name;
        $this->balance = new Money(0, new Currency($currency));
        if(is_null($isActive)){
            $this->activate('Create new Wallet');
        }
        
        if (is_null($isRecovering) == true) {
            $this->isRecovering = true;
        }
        
    }
    
    
    public function fromEvents(): Wallet
    {
        $events = $this->provider->provideEvents();
        $wallet = new Wallet($this->name,
            $this->balance->getCurrency(),
            $this->serializer,
            $this->provider,
            true,
            true);
        foreach ($events as $event) {
            if ($event instanceof WalletEvent) {
                $event->recreate($wallet);
            }
        }
        $wallet->changeRecoveringState();
        return $wallet;
    }
    
    public function deposit(Money $moneyToDeposit): void
    {
        if ($this->isActive) {
            if ($moneyToDeposit->isSameCurrency($this->balance)) {
                $this->balance = $this->balance->add($moneyToDeposit);
                if (!($this->isRecovering)) {
                    $this->serializer->serialize(new DepositToWalletEvent($moneyToDeposit));
                }
            }
            else {
                throw new DifferentCurrenciesException();
            }
        }
        else {
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
                        $this->serializer->serialize(new WithdrawFromWalletEvent($moneyToWithdraw));
                    }
                }
                else {
                    throw new NotEnoughMoneyInWalletException();
                }
            }
            else {
                throw new DifferentCurrenciesException();
            }
        }
        else {
            throw new InactiveWalletException();
        }
    }
    
    public function deactivate(string $reason): void
    {
        if ($this->isActive) {
            $this->isActive = false;
            if (!($this->isRecovering)) {
                $this->serializer->serialize(new DeactivateWalletEvent($reason));
            }
        }
        else {
            throw new InactiveWalletException('You cannot deactivate inactive wallet!');
        }
    }
    
    public function activate(string $reason): void
    {
        if ($this->isActive == false) {
            $this->isActive = true;
            if (!($this->isRecovering)) {
                $this->serializer->serialize(new ActivateWalletEvent($reason));
            }
        }
        else {
            throw new ActiveWalletException('You cannot activate active wallet!');
        }
    }
    
    public function getBalance(): Money
    {
        return $this->balance;
    }
    
    public function changeRecoveringState()
    {
        $this->isRecovering = !($this->isRecovering);
    }

    public function getName() :string
    {
        return $this->name;
    }
}
