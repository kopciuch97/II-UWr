<?php
namespace src\DataProviders;

interface IDataProvider{
  public function getOne(int $id);
  public function getAll();
}