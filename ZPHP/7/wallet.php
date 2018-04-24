<?php
require_once 'vendor/autoload.php';
use Wallet\Wallet;
use Money\Money;
use Money\Currency;
//use EventSerializers\FileEventSerializer;
//use EventProviders\SerializedObjectsProvider;



$curr = $argv[1];
$wallet1 = new Wallet('wallet1', $curr);
for($i=0; $i < $argv[2]; $i++){
    $wallet1->deposit(new Money($argv[$i+3], new Currency($curr)));
}
    $wallet1->withdraw(new Money($argv[count($argv) -1], new Currency($curr)));
    echo $wallet1->getBalance()->getAmount() . PHP_EOL;



//foreach((array_diff(scandir(__DIR__ . '/data'), array('..', '.'))) as $file){
//    unlink(__DIR__ . '/data/' . $file);
//};

