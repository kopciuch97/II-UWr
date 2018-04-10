<?php

namespace src\Deserializers;

interface IDeserializer {
  public function deserialize(int $id);
  public function getPath();
}