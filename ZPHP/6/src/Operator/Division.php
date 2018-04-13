<?php
namespace Operator;

class Division implements BinaryOperator{
    private static $instance = null;
    private static $symbol = '/';
    private function __construct()
    {
    }
    

    public static function getInstance()
    {
        if(self::$instance == null){
            self::$instance = new Division();
        }
        return self::$instance;
    }
    
    public function calc(float $firstArgument, float $secondArgument)
    {
        if($secondArgument == 0){
            throw new \InvalidArgumentException("Division by 0!");
        }
        return $firstArgument/$secondArgument;
    }
    
    public function getSymbol()
    {
        return self::$symbol;
    }
    
    
}