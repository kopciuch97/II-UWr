<?php
namespace CommandBus;

use Commands\Command;
use Routers\Router;

interface ICommandBus{
    public function dispatch(Command $command);
}