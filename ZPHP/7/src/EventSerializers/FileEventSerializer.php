<?php

namespace src\EventSerializers;

use src\Events\WalletEvent;

class FileEventSerializer implements EventSerializer{
    private $RelativePath;
    
    /**
     * FileEventSerializer constructor.
     * @param $RelativePath
     */
    public function __construct($RelativePath)
    {
        $this->RelativePath = __DIR__ . $RelativePath;
    }
    
    
    public function serialize(WalletEvent $event) : void
    {
        file_put_contents($this->RelativePath . $this->getNextId(), serialize($event));
    }
    
    private function getNextId() : int
    {
        return count(scandir($this->RelativePath)) - 2;
    }
}