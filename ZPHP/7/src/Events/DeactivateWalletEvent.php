<?php
namespace Events;

use Wallet\Wallet;

class DeactivateWalletEvent implements WalletEvent {
    private $reason;
    
    /**
     * DeactivateWalletEvent constructor.
     * @param $reason
     */
    public function __construct(string $reason)
    {
        $this->reason = $reason;
    }
    
    public function recreate(Wallet $wallet)
    {
        $wallet->deactivate($this->reason);
    }
}