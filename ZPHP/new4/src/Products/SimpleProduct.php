<?php

namespace src\Products;

use Money\Money;
use Money\Currency;

class SimpleProduct implements IProduct
{
  private $id;
  private $name;
  private $money;

  /**
   * SimpleProduct constructor.
   * @param int $id
   * @param string $name
   * @param Money $money
   */
  public function __construct(int $id, string $name, Money $money)
  {
    $this->id = $id;
    $this->name = $name;
    $this->money = $money;
  }

  /**
   * @return string
   */
  public function getName() : string
  {
    return $this->name;
  }

  /**
   * @return int
   */
  public function getId() : int
  {
    return $this->id;
  }

  /**
   * @return Money
   */
  public function getMoney() : Money
  {
    return $this->money;
  }

  /**
   * @param array $newValues
   */
  public function editProduct(array $newValues)
  {
    if (array_key_exists("name", $newValues)) {
      $this->name = $newValues["name"];
    }

    if (array_key_exists("amout", $newValues) && array_key_exists("currency", $newValues)) {
      $this->money = new Money($newValues["amount"], new Currency($newValues["currency"]));
    }
  }
}

