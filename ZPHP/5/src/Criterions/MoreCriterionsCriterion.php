<?php

namespace Criterions;

use Cart\Cart;

class MoreCriterionsCriterion implements Criterion
{
    private $criterions;
    
    /**
     * MoreCriterionsCriterion constructor.
     * @param Criterion[] ...$criterions
     */
    public function __construct(Criterion ... $criterions)
    {
        $this->criterions = $criterions;
    }
    
    public function qualifyToPromote(Cart $cart): bool
    {
        if ($cart->count() == 0) {
            return false;
        } else {
            foreach ($this->criterions as $criterion) {
                if ($criterion->qualifyToPromote($cart) == false) {
                    return false;
                }
            }
            return true;
        }
    }
    
}