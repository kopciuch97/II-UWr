<?php

namespace Criterions;
use Cart\Cart;
interface Criterion
{
    public function qualifyToPromote(Cart $cart) :bool;
}