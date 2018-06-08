<?php
require 'vendor/autoload.php';

use Commands\Command;
use Commands\PingCommand;
use Commands\PongCommand;
use CommandBus\CommandBus;
use Routers\DirectRouter;
use Handlers\PingHandler;
use Handlers\PongHandler;

$router = new DirectRouter([
    PingCommand::class =>PingHandler::class,
    PongCommand::class =>PongHandler::class
]);

$commandBus = new CommandBus($router);
$commandBus->dispatch(new PingCommand());
$commandBus->dispatch(new PongCommand());



