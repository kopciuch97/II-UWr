<?php
namespace Product;

use Money\Money;

class StandardProduct implements Product{
    private $name;
    private $price;
    
    /**
     * StandardProduct constructor.
     * @param string $name
     * @param Money $price
     */
    public function __construct(string $name, Money $price)
    {
        $this->name = $name;
        $this->price = $price;
    }
    
    /**
     * @return string
     */
    public function getName(): string
    {
        return $this->name;
    }
    
    /**
     * @return Money
     */
    public function getPrice(): Money
    {
        return $this->price;
    }
    
}