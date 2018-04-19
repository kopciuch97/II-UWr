<?php
namespace Events;

use Wallet\Wallet;

class CreateWalletEvent implements WalletEvent {
    private $name;
    private $currency;
    public function __construct(string $name, string $currency)
    {
        $this->name = $name;
        $this->currency = $currency;
    }
    
    public function recreate(Wallet $wallet)
    {
        return new Wallet($this->name, $this->currency, null, true );
    }
}