<?php
namespace Operator;

interface BinaryOperator {
    public function calc(float $firstArgument, float $secondArgument);
    public function getSymbol();
    
}