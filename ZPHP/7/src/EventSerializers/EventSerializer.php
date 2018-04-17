<?php

namespace src\EventSerializers;

use src\Events\WalletEvent;

interface EventSerializer{
    public function serialize(WalletEvent $event);
}