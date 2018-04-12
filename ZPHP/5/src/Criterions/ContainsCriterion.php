<?php
namespace Criterions;
use Product\Product;
use Cart\Cart;

class ContainsCriterion implements Criterion{
    private $name;
    
    /**
     * ContainsCriterion constructor.
     * @param $name
     */
    public function __construct(string $name)
    {
        $this->name = $name;
    }
    
    /**
     * @param Cart $cart
     * @return bool
     */
    public function qualifyToPromote(Cart $cart): bool
    {
        if($cart->count()==0){
            return false;
        }
        foreach ($cart->getProducts() as $product){
            if($product instanceof Product && $product->getName() == $this->name){
                    return true;
            }
        }
        return false;
    }
    
}