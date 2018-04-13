<?php
namespace Operator;
class Addition implements BinaryOperator{
    private static $instance = null;
    private static $symbol = '+';
    
    private function __construct()
    {
    }
    
    public static function getInstance(){
        if(self::$instance == null){
            self::$instance = new Addition();
        }
        return self::$instance;
    }
    
    public function calc(float $firstArgument,float $secondArgument) :int
    {
        return $firstArgument + $secondArgument;
    }
    
    public function getSymbol()
    {
        return self::$symbol;
    }
}