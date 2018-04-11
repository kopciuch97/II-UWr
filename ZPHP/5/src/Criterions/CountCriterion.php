<?php
namespace src\Criterions;
use src\Cart\Cart;
class CountCriterion implements Criterion{
    private $count;
    
    /**
     * CountCriterion constructor.
     * @param $count
     */
    public function __construct(int $count)
    {
        $this->count = $count;
    }
    
    /**
     * @param Cart $cart
     * @return bool
     */
    public function qualifyToPromote(Cart $cart): bool
    {
        return $cart->count() >= $this->count;
    }
}