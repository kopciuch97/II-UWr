<?php

namespace EventProviders;


use Wallet\Wallet;

interface EventProvider{
    public function provideEvents(Wallet $wallet) : array;
}