<?php

namespace Stack;

class Stack {
    private $array;
    
    public function __construct(array $arr)
    {
        $this->array = $arr;
    }
    
    public function size() {
        return count($this->array);
    }
    public function push($value) {
        array_push($this->array, $value);
    }
    
    public function pop() {
        if(count($this->array) == 0)
            throw new \Exception('Stack is empty! You cannot pop from empty stack.');
        return array_pop($this->array);
    }
    
}