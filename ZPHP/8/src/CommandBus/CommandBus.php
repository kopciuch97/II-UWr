<?php
namespace CommandBus;
use Commands\Command;
use Routers\Router;

class CommandBus implements ICommandBus
{
    private $router;
    
    public function __construct(Router $router)
    {
        $this->router = $router;
    }
    
    public function dispatch(Command $command)
    {
        $handler_name = $this->router->direct($command);
        $handler_object = new $handler_name();
        $handler_object($command);
        var_dump($handler_name);
        var_dump($handler_object);
    }
}
