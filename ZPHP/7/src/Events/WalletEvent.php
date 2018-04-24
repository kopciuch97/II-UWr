<?php

namespace Events;

use Wallet\Wallet;

interface WalletEvent{
    public function recreate(Wallet $wallet);
}