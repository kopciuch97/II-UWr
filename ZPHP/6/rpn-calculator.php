<?php

require 'vendor/autoload.php';
use Calculator\CalculatorRNP;
use Stack\Stack;
use Operator\Addition;
use Operator\Subtraction;
use Operator\Multiply;
use Operator\Division;

$op = array(Addition::getInstance(), Subtraction::getInstance(), Multiply::getInstance(), Division::getInstance());
$st = new Stack(array());
$calculator = new CalculatorRNP($st, $op);

try {
    for ($i = 1; $i < sizeof($argv); $i++) {
        echo $argv[$i] . " = " . $calculator->calculate($argv[$i]) . PHP_EOL;
    }
}
catch(Exception $e){
   echo $e->getMessage() . PHP_EOL;
    
    
}
