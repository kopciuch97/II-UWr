<?php
namespace Events;

use Money\Money;
use Wallet\Wallet;

class WithdrawFromWalletEvent implements WalletEvent {
    private $amount;
    
    /**
     * WithdrawFromWalletEvent constructor.
     * @param $amount
     */
    public function __construct(Money $amount)
    {
        $this->amount = $amount;
    }
    
    
    public function recreate(Wallet $wallet)
    {
        $wallet->withdraw($this->amount);
        
    }
}