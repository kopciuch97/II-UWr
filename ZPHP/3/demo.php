<?php

require 'vendor/autoload.php';

use Money\Money;
use src\Product as Product;
use src\Bundle as Bundle;
use src\Discounted as Discounted;

$product1 = new Product("produkt 1", Money::PLN(10000));
$product2 = new Product("produkt 2", Money::PLN(10000));
$bundle1 = new Bundle("bundle 1");
$bundle1->addProduct($product1);
$bundle1->addProduct($product2);
$discount1 = new Discounted("discount1", $bundle1, 25);
$totalPrice = Money::PLN(0);

$products = [
    $product1,
    $product2,
    $bundle1,
    $discount1
    // ... w tym miejscu powinny się znaleźć także zestawy produktów i produkty przecenione
];

foreach ($products as $product) {
    echo $product->getName() . PHP_EOL;

    $totalPrice = $totalPrice->add($product->getPrice());
}


echo 'TOTAL PRICE ' . $totalPrice->getAmount() . PHP_EOL;



