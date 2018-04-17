<?php

namespace src\Events;

use src\Wallet\Wallet;

interface WalletEvent{
    public function recreate(Wallet $wallet) ;
}