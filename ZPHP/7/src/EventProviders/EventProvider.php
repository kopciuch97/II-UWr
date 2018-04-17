<?php

namespace src\EventProviders;

use src\Events\WalletEvent;

interface EventProvider{
    public function provideEvents() : array;
}