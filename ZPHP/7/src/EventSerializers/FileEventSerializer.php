<?php

namespace EventSerializers;

use Events\WalletEvent;

class FileEventSerializer implements EventSerializer{
    private $Path;
    private $walletName;
    
    /**
     * FileEventSerializer constructor.
     * @param $RelativePath
     */
    public function __construct(string $walletName)
    {
        $this->Path = __DIR__ . '/../../data/';
        $this->walletName = $walletName;
    }
    
    
    public function serialize(WalletEvent $event) : void
    {
        file_put_contents($this->Path . $walletName . '/' . $this->getNextId(), serialize($event));
    }
    
    private function getNextId() : int
    {
        return count(scandir($this->Path)) - 1;
    }
}