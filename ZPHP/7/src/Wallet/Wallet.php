<?php

namespace Wallet;

use Events\ActivateWalletEvent;
use Events\DeactivateWalletEvent;
use Events\DepositToWalletEvent;
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
    private $serializer;
    private $provider;
    
    /**
     * Wallet constructor.
     * @param string $name
     * @param string $currency
     * @param EventSerializer|null $serializer
     * @param EventProvider|null $provider
     * @throws ActiveWalletException
     */
    public function __construct(string $name, string $currency,
                                EventSerializer $serializer = NULL,
                                EventProvider $provider = NULL)
    {
        $this->name = $name;
        $this->balance = new Money(0, new Currency($currency));
        if (is_null($provider)){
            $this->provider = new SerializedObjectsProvider('/../../data/');
        }
        if(is_null($serializer)){
            $this->serializer = new FileEventSerializer('/../../data/');
        }
        $this->activate('Create new Wallet');
    }
    
    
    public function fromEvents(): Wallet
    {
        $events = $this->provider->provideEvents();
        $wallet = new Wallet($this->name,
                             $this->balance->getCurrency(),
                             $this->serializer,
                             $this->provider);
        foreach ($events as $event){
            $event->recreate($wallet);
        }
        
        return $wallet;
        
        
    }
    
    public function deposit(Money $moneyToDeposit): void
    {
        if ($this->isActive) {
            if ($moneyToDeposit->isSameCurrency($this->balance)) {
                $this->balance->add($moneyToDeposit);
                $this->serializer->serialize(new DepositToWalletEvent($moneyToDeposit));
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
                    $this->balance->subtract($moneyToWithdraw);
                    $this->serializer->serialize(new WithdrawFromWalletEvent($moneyToWithdraw));
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
        if($this->isActive){
            $this->isActive = false;
            $this->serializer->serialize(new DeactivateWalletEvent($reason));
        }
        else{
            throw new InactiveWalletException('You cannot deactivate inactive wallet!');
        }
    }
    
    public function activate(string $reason): void
    {
        if($this->isActive == false){
            $this->isActive = true;
            $this->serializer->serialize(new ActivateWalletEvent($reason));
        }
        else{
            throw new ActiveWalletException('You cannot activate active wallet!');
        }
    }
    
    public function getBalance(): Money
    {
        return $this->balance;
    }
    
}