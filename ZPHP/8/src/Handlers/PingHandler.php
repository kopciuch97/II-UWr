<?php
namespace Handlers;
use Commands\PingCommand;

class PingHandler
{
    public function __invoke(PingCommand $command)
    {
        echo $command->execute() . PHP_EOL;
    }
}