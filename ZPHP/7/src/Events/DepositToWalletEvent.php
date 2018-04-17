<?php
namespace src\Events;

use Money\Money;
use src\Wallet\Wallet;

class DepositToWalletEvent implements WalletEvent {
    private $amount;
    
    /**
     * DepositToWalletEvent constructor.
     * @param $amount
     */
    public function __construct(Money $amount)
    {
        $this->amount = $amount;
    }
    
    
    public function recreate(Wallet $wallet)
    {
        $wallet->deposit($this->amount);
    }
    
    
}