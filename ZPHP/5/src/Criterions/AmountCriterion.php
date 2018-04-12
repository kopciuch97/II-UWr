<?php

namespace Criterions;

use Cart\Cart;

class AmountCriterion implements Criterion{
    private $amount;
    
    /**
     * AmountCriterion constructor.
     * @param $amount
     */
    public function __construct(int $amount)
    {
        $this->amount = $amount;
    }
    
    /**
     * @param Cart $cart
     * @return bool
     */
    public function qualifyToPromote(Cart $cart): bool
    {
        return $cart->getTotalPrice()->getAmount() >= $this->amount;
    }
}