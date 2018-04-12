<?php
namespace Criterions;

use Cart\Cart;

class OneOfMoreCriterionsCriterion implements Criterion{
    private $criterions;
    
    /**
     * OneOfMoreCriterionsCriterion constructor.
     * @param Criterion[] ...$criterions
     */
    public function __construct(Criterion ... $criterions)
    {
        $this->criterions = $criterions;
    }
    
    public function qualifyToPromote(Cart $cart): bool
    {
        if($cart->count() == 0){
            return false;
        }
        foreach ($this->criterions as $criterion ){
            if($criterion->qualifyToPromote($cart)){
                return true;
            }
        }
        return false;
    }
    
    
}