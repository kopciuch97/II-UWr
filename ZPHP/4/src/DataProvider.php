<?php

namespace src;
class DataProvider
{
    private $path;
    private $numberOfObjects;

    /**
     * DataManager constructor.
     * @param string $path
     */
    public function __construct(string $path)
    {
        $this->path = $path;
        $this->numberOfObjects = file_get_contents($path . 'counter');
    }

    /**
     * @param int $id
     * @return string
     */
    public function getContent(int $id): string {
        return file_get_contents($this->path . $id . '.json');
    }

    /**
     * @param int $id
     * @param $content
     */
    public function putJsonContent(int $id, $content ){
        file_put_contents($this->path . $id . '.json', $content);
    }

    public function incNumberOfObjects(){
        $counter =  file_get_contents($this->path  . 'counter');
        $counter += 1;
        file_put_contents($this->path . 'counter', $counter);
    }
}