<?php
namespace src\Events;

use src\Wallet\Wallet;

class ActivateWalletEvent implements WalletEvent {
    private $reason;
    
    /**
     * ActivateWalletEvent constructor.
     * @param $reason
     */
    public function __construct(string $reason)
    {
        $this->reason = $reason;
    }
    
    
    public function recreate(Wallet $wallet)
    {
        $wallet->activate($this->reason);
    }
    
}