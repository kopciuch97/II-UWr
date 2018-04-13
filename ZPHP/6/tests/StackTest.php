<?php

use PHPUnit\Framework\TestCase;
use Stack\Stack;

class StackkTest extends TestCase
{
    public function testPop()
    {
        $stack = new Stack([5]);
        $this->assertEquals(5, $stack->pop());
        $this->assertEquals(0, $stack->size());
        $this->expectException(Exception::class);
        $stack->pop();
    }
    
    public function testSizeOfStackAndPush()
    {
        $stack = new Stack([]);
        $this->assertEquals(0, $stack->size());
        $stack->push(4);
        $this->assertEquals(1, $stack->size());
        for ($i = 0; $i < 100; $i++) {
            $stack->push($i);
        }
        $this->assertEquals(101, $stack->size());
    }
}