<?php

namespace Commands;

class PingCommand extends Command
{
    public function __construct()
    {
        $this->timestamp = new \DateTime('now');
    }
    
    public function execute()
    {
        return 'PING';
    }
}