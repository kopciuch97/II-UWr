<?php

namespace EventSerializers;

use Events\WalletEvent;

class FileEventSerializer implements EventSerializer{
    private $Path;
    
    /**
     * FileEventSerializer constructor.
     * @param string $walletName
     */
    public function __construct(string $walletName)
    {
        $this->Path = __DIR__ . '/../../data/' . $walletName . '/';
    }
    
    
    public function serialize(array $events) : void
    {
        if (!file_exists($this->Path)) {
            mkdir($this->Path, 0777, true);
        }
        foreach($events as $event) {
            file_put_contents($this->Path . $this->getNextId(), serialize($event));
        }
    }
    
    private function getNextId() : int
    {
        return count(scandir($this->Path)) - 1;
    }
}