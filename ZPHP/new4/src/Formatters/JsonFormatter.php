<?php

namespace src\Formatters;

use src\Products\IProduct;

class JsonFormatter implements IFormatter {


  /**
   * JsonFormatter constructor.
   */
  public function __construct()
  {
  }

  public function format(IProduct $product)
  {
    return json_encode($product, JSON_PRETTY_PRINT);
  }
}