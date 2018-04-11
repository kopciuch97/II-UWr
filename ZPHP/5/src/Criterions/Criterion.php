<?php

namespace src\Criterions;
use src\Cart\Cart;
interface Criterion
{
    public function qualifyToPromote(Cart $cart) :bool;
}