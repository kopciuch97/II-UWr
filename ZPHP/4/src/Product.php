<?php

namespace src;

use Money\Money;
use Money\Currency;
class Product
{
    private $id;
    private $name;
    private $money;

    /**
     * Product constructor.
     * @param $id
     * @param $name
     * @param $value
     * @param $currency
     */
    public function __construct(
        $id, $name, $value, $currency){
        $this->id = $id;
        $this->name = $name;
        $this->money = new Money($value,
            new Currency($currency));
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