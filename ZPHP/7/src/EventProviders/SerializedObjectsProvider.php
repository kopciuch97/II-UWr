<?php

namespace EventProviders;
use Wallet\Wallet;


class SerializedObjectsProvider implements EventProvider{
    private $Path;
    
    public function __construct()
    {
        $this->Path = __DIR__ . '/../../data/';
    }
    
    public function provideEvents(Wallet $wallet) : array
    {
        $ObjectDirectoryPath = $this->Path . $wallet->getName() . '/';
        $objects = array();
        foreach (array_diff(scandir($ObjectDirectoryPath), array('..', '.')) as $file) {
            array_push($objects, unserialize(file_get_contents($ObjectDirectoryPath . $file)));
        }
       // sort($objects);
        return $objects;
    }
}