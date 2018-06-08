<?php

namespace Commands;

class PongCommand extends Command
{
    public function __construct()
    {
        $this->timestamp = new \DateTime('now');
    }
    
    public function execute()
    {
        return 'PONG';
    }
}