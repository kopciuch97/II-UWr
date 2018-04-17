<?php

namespace src\Wallet;

use Money\Money;
use Money\Currency;
use InvalidArgumentException;
use Exception;
use src\EventProviders\EventProvider;
use src\EventProviders\SerializedObjectsProvider;
use src\EventSerializers\EventSerializer;
use src\EventSerializers\FileEventSerializer;

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
     */
    public function __construct(string $name, string $currency,
                                EventSerializer $serializer = NULL,
                                EventProvider $provider = NULL)
    {
        $this->name = $name;
        $this->balance = new Money(0, new Currency($currency));
        if ($provider == NULL){
            $this->provider = new SerializedObjectsProvider('/../../data/');
        }
        if($serializer == NULL){
            $this->serializer = new FileEventSerializer('/../../data/');
        }
        $this->activate('Create new Wallet');
    }
    
    
    public static function fromEvents(array $events): Wallet
    {
        return new Wallet('test', 'test');
    }
    
    public function deposit(Money $moneyToDeposit): void
    {
        if ($this->isActive) {
            if ($moneyToDeposit->isSameCurrency($this->balance)) {
                $this->balance->add($moneyToDeposit);
//                TODO: MAKE DepositEventObj & Serialize
            } else {
                throw new InvalidArgumentException('Currency you want is different than in Wallet!');
            }
        } else {
            throw new Exception('Your Wallet is inactive! Contact our support.');
        }
    }
    
    public function withdraw(Money $moneyToWithdraw): void
    {
        if ($this->isActive) {
            if ($moneyToWithdraw->isSameCurrency($this->balance)) {
                if ($moneyToWithdraw->lessThanOrEqual($this->balance)) {
                    $this->balance->subtract($moneyToWithdraw);
//                    TODO: MAKE WithdrawEventObj & Serialize
                } else {
                    throw new InvalidArgumentException('You dont have enough money to withdraw!');
                }
            } else {
                throw new InvalidArgumentException('Currency you want is different than in Wallet!');
            }
        } else {
            throw new Exception('Your Wallet is inactive! Contact our support.');
        }
    }
    
    public function deactivate(string $reason): void
    {
        if($this->isActive){
            $this->isActive = false;
//            TODO : Make DeactivateEventObj & Serialize
        }
        else{
//            TODO: Exception deactivate deavtive wallet
        }
    }
    
    public function activate(string $reason): void
    {
        if($this->isActive == false){
            $this->isActive = true;
//            TODO: Make ActivateEventObj & Serialize
        }
        else{
//            TODO: Exception activate active wallet
        }
    }
    
    public function getBalance(): Money
    {
        return $this->balance;
    }
    
    // ...
    
}