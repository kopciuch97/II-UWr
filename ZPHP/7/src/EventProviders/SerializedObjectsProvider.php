<?php

namespace EventProviders;


class SerializedObjectsProvider implements EventProvider{
    private $RelativePath;
    
    public function __construct($RelativePath)
    {
        $this->RelativePath = __DIR__ . $RelativePath;
    }
    
    public function provideEvents() : array
    {
        $objects = array();
        foreach (array_diff(scandir($this->RelativePath), array('..', '.')) as $file) {
            array_push($objects, unserialize(file_get_contents($this->RelativePath . $file)));
        }
        sort($objects);
        return $objects;
    }
}