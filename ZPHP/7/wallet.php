<?php
require_once 'vendor/autoload.php';
use Wallet\Wallet;
use Money\Money;
use Money\Currency;
use EventSerializers\FileEventSerializer;


$wallet1 = new Wallet('wallet1', 'PLN');
$wallet1Serializer = new FileEventSerializer($wallet1->getName());
$wallet1Serializer->serialize($wallet1->deposit(new Money(10, new Currency('PLN'))));
$wallet1Serializer->serialize($wallet1->deposit(new Money(20, new Currency('PLN'))));
$wallet1Serializer->serialize($wallet1->deposit(new Money(30, new Currency('PLN'))));




//foreach((array_diff(scandir(__DIR__ . '/data'), array('..', '.'))) as $file){
//    unlink(__DIR__ . '/data/' . $file);
//};

