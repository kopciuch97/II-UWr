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
     * @param int $id
     * @param string $name
     * @param float $value
     * @param string $currency
     */
    public function __construct(int $id, string $name, float $value, string $currency)
    {
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

    /**
     * @return Money
     */
    public function getPrice(): Money
    {
        return $this->money;
    }

    /**
     * @return int
     */

    public function getId(): int
    {
        return $this->id;
    }
}