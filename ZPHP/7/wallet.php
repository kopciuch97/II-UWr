<?php
require_once 'vendor/autoload.php';
use Wallet\Wallet;
use Money\Money;
use Money\Currency;
$wallet = new Wallet('w1', 'PLN');

$wallet->deposit(new Money(10, new Currency('PLN')));
$wallet->deposit(new Money(10, new Currency('PLN')));
$wallet->deposit(new Money(10, new Currency('PLN')));
$wallet->withdraw(new Money(10, new Currency('PLN')));


$wallet2 = $wallet->fromEvents();
echo $wallet2->getBalance()->getAmount() . PHP_EOL;



foreach((array_diff(scandir(__DIR__ . '/data'), array('..', '.'))) as $file){
    unlink(__DIR__ . '/data/' . $file);
};

