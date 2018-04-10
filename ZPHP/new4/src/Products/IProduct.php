<?php
namespace src\Products;

interface IProduct
{
  public function getId();
  public function getName();
  public function getMoney();
  public function editProduct(array $newValues);
}