<?php

namespace src\Serializers;

use src\Products\IProduct;

interface ISerializer{
  public function serialize(IProduct $product);
}