<?php
namespace Routers;

use Commands\Command;
use Exception;
class DirectRouter implements Router
{
    private $handlers;
    
    public function __construct(Array $handlers)
    {
        $this->handlers = $handlers;
    }
    public function direct(Command $command)
    {
        if(array_key_exists(get_class($command),
            $this->handlers)){
            return $this->handlers[get_class(
                $command)];
        }
        else{
            throw new Exception('No route find');
        }
    }
}
