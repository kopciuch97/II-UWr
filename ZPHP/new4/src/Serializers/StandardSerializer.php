<?php

namespace src\Serializers;

use src\Products\IProduct;

class StandardSerializer implements ISerializer
{

  private $path;

  /**
   * StandardSerializer constructor.
   * @param $path
   */

  public function __construct($path)
  {
    $this->path = $path;
  }

  public function serialize(IProduct $product)
  {
    file_put_contents($this->path . $this->getCounter(), serialize($product));
    $this->incCounter();
  }

  public function serializeId(IProduct $product, int $id)
  {
    file_put_contents($this->path . $id, serialize($product));
  }

  public function getCounter()
  {
    return file_get_contents(__DIR__ . '/../../data/counter');
  }

  private function incCounter()
  {
    $counter = $this->getCounter();
    $counter += 1;
    file_put_contents(__DIR__ . '/../../data/counter', $counter);
  }

}