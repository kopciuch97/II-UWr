<?php

namespace src\Formatters;

use src\Products\IProduct;

interface IFormatter{
  public function format(IProduct $product);
}