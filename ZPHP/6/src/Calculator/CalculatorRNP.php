<?php

namespace Calculator;

use Operator\BinaryOperator;
use Stack\Stack;

class CalculatorRNP implements Calculator
{
    private $stack;
    private $operators;
    
    public function __construct(Stack $stack, array $binaryOperators)
    {
        $this->stack = $stack;
        $this->operators = $binaryOperators;
    }
    
    private function acceptableOperators() : array{
        $acctable = array();
        foreach ($this->operators as $operator){
            array_push($acctable, $operator->getSymbol());
        }
        
        return $acctable;
    }
    
    private function splitExpression(string $expression) : array {
        return explode(" ", $expression);
    }
    
    public function calculate(string $expression)
    {
        $expr = $this->splitExpression($expression);
        $operators = $this->acceptableOperators();
        foreach ($expr as $value){
            if(is_numeric($value)){
                $this->stack->push($value);
            }
            
            if(in_array($value, $operators)){
                foreach ($this->operators as $operator){
                    if ($operator->getSymbol() == $value) {
                        if($operator instanceof BinaryOperator){
                            if ($this->stack->size() < 2){
                                throw new \Exception('Invalid RPN expression!');
                            }
                        }
                        $this->stack->push($operator->calc($this->stack->pop(), $this->stack->pop()));
                    }
                }
            }
        
        }
        return $this->stack->pop();
    }
}