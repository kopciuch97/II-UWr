<?php
namespace Routers;

use Commands\Command;

interface Router{
    public function direct(Command $command);
}