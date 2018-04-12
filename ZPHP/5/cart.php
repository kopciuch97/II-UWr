<?php

require_once 'vendor/autoload.php';

use Money\{
    Money, Currency
};
use Criterions\AmountCriterion;
use Criterions\ContainsCriterion;
use Criterions\CountCriterion;
use Criterions\MoreCriterionsCriterion;
use Criterions\OneOfMoreCriterionsCriterion;
use Product\StandardProduct;
use Cart\Cart;

$amountCrit = new AmountCriterion(1500);
$containsCrit = new ContainsCriterion("TELEFON");
$countCrit = new CountCriterion(6);
$allOfCrits = new MoreCriterionsCriterion($amountCrit, $containsCrit, $countCrit);
$oneOfCrits = new OneOfMoreCriterionsCriterion($amountCrit, $countCrit, $containsCrit);

$product1 = new StandardProduct('TELEFON', new Money(700, new Currency('PLN')));
$product2 = new StandardProduct('KABEL USB', new Money(15, new Currency('PLN')));
$product3 = new StandardProduct('SLUCHAWKI', new Money(100, new Currency('PLN')));
$product4 = new StandardProduct('POKROWIEC', new Money(50, new Currency('PLN')));
$product5 = new StandardProduct('SZKLO HARTOWANE', new Money(20, new Currency('PLN')));
$product6 = new StandardProduct('GLOSNIK BLUETOOTH', new Money(250, new Currency('PLN')));
$product7 = new StandardProduct('POWERBANK', new Money(150, new Currency('PLN')));

$cart1 = new Cart();
$cart1->addProduct($product1);
$cart1->addProduct($product2);
$cart1->addProduct($product3);
$cart1->addProduct($product4);
$cart1->addProduct($product5);
//echo $cart1->count() . PHP_EOL;
//echo $cart1->getTotalPrice()->getCurrency() . PHP_EOL;
//echo $cart1->getTotalPrice()->getAmount() . PHP_EOL;

if ($countCrit->qualifyToPromote($cart1)){
    echo 'tak' . PHP_EOL;
}
else{
    echo 'nie' . PHP_EOL;
}