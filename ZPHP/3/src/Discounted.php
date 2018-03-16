<?php

namespace src;

use Money\Money;

class Discounted implements IProduct
{
    private $name;
    private $product;
    private $discount;

    /**
     * Discounted constructor.
     * @param string $name
     * @param Iproduct $product
     * @param int $discount
     */
    public function __construct(string $name, IProduct $product, int $discount)
    {
        $this->name = $name;
        $this->product = $product;
        $this->discount = $discount;
    }

    public function getPrice(): Money
    {
        return $this->product->getPrice()->multiply(1 - ($this->discount / 100));
    }

    public function getName(): string
    {
        return $this->name;
    }

}