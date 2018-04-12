<?php

namespace Product;

use Money\Money;

interface Product
{
    public function getName(): string;
    
    public function getPrice(): Money;
}