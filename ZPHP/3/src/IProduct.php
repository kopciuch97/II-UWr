<?php
namespace src;
use Money\Money;
interface IProduct
{
    /**
     * @return string
     */
    public function getName(): string;

    /**
     * @return Money
     */
    public function getPrice(): Money;
}