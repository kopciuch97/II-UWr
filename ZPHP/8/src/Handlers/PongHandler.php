<?php
namespace Handlers;
use Commands\PongCommand;

class PongHandler
{
    public function __invoke(PongCommand $command)
    {
        echo $command->execute() . PHP_EOL;
    }
}