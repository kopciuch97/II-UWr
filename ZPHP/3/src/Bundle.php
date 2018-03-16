<?php

namespace src;

use Money\Money;


class Bundle implements IProduct
{
    private $name;
    private $bundle = array();
    private $totalValue;


    /**
     * Bundle constructor.
     * @param string $name
     */
    public function __construct(string $name)
    {
        $this->name = $name;
        $this->totalValue = Money::PLN(0);
    }

    /**
     * @return Money
     */
    public function getPrice(): Money
    {
        return $this->totalValue;
    }

    public function getName(): string
    {
        return $this->name;
    }

    /**
     * @param IProduct $product
     */
    public function addProduct(IProduct $product): void
    {
        array_push($this->bundle, $product);
        $price = $product->getPrice();
        $this->totalValue = $this->totalValue->add($product->getPrice());

    }


}
