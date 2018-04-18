<?php

namespace EventSerializers;

use Events\WalletEvent;

interface EventSerializer{
    public function serialize(WalletEvent $event);
}