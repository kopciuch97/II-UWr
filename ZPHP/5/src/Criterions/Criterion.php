<?php

namespace src\Criterions;
interface Criterion
{
    public function qualifyToPromote(Cart $cart) :bool;
}