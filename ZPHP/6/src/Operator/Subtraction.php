<?php
namespace Operator;

class Subtraction implements BinaryOperator{
    private static $instance = null;
    private static $symbol = '-';
    private function __construct()
    {
    }
    
    public static function getInstance()
    {
        if(self::$instance == null){
            self::$instance = new Subtraction();
        }
        return self::$instance;
    }
    
    public function calc(float $firstArgument, float $secondArgument)
    {
        return $secondArgument - $firstArgument;
    }
    
    public function getSymbol()
    {
        return self::$symbol;
    }
}