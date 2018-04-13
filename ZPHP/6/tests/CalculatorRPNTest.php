<?php

use PHPUnit\Framework\TestCase;
use Stack\Stack;
use Calculator\CalculatorRNP;
use Operator\Addition;
use Operator\Subtraction;
use Operator\Multiply;
use Operator\Division;

class CalculatorRPNTest extends TestCase
{
    public function testRpnInvalidExpressionNotOperatorOnLastPosition()
    {
        $op = [Addition::getInstance()];
        $stack = new Stack([]);
        $calc = new CalculatorRNP($stack, $op);
        
        $this->expectException(Exception::class);
        $calc->calculate("3 + 5");
    }
    
    public function testSimpleAdditionTest(){
        $op = [Addition::getInstance()];
        $stack = new Stack([]);
        $calc = new CalculatorRNP($stack, $op);
        $this->assertEquals(10, $calc->calculate("7 3 +"));
    }
    
    public function testMoreOperatorsTest(){
        $op = [Addition::getInstance(), Subtraction::getInstance(), Multiply::getInstance(), Division::getInstance()];
        $stack = new Stack([]);
        $calc = new CalculatorRNP($stack, $op);
        $this->assertEquals(10, $calc->calculate('3 5 + 6 * 2 + 10 - 4 /'));
    }
}