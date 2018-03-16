<?php

namespace src;

use Money\Money;

class Product implements IProduct
{
    private $name;
    private $price;

    /**
     * Product constructor.
     * @param $name
     * @param $price
     */
    public function __construct($name, Money $price)
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

    public function getPrice(): Money
    {
        return $this->price;
    }
}