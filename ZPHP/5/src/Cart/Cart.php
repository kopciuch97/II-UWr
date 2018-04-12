<?php

namespace Cart;

use Money\Money;
use Money\Currency;
use Product\Product;
use Countable;

class Cart implements Countable
{
    private $products = array();
    
    /**
     * Cart constructor.
     */
    public function __construct()
    {
        //$this->products = array();
    }
    
    /**
     * @param Product $product
     */
    public function addProduct(Product $product)
    {
        array_push($this->products, $product);
    }
    
    /**
     * @return Money
     */
    public function getTotalPrice(): Money
    {
        if ($this->count()) {
            return new Money(0, new Currency('PLN'));
        }
        $totalAmount = new Money(0, $this->products[0]->getPrice()->getCurrency());
        
        foreach ($this->products as $product) {
            
            $totalAmount = $totalAmount->add($product->getPrice());
            
            }
        
        return $totalAmount;
    }
    
    /**
     * @return int
     */
    public function count()
    {
        return count($this->products);
    }
    
    /**
     * @return array
     */
    public function getProducts(): array
    {
        return $this->products;
    }
}