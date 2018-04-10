<?php

namespace src\DataProviders;

use src\Deserializers\IDeserializer;
use src\Formatters\IFormatter;
use src\Serializers\ISerializer;

class JsonDataProvider implements IDataProvider {
  private $path;
  private $serializer;
  private $deserializer;
  private $formatter;

  /**
   * JsonDataProvider constructor.
   * @param $deserializer
   * @param $formatter
   */
  public function __construct(IDeserializer $deserializer,
                              IFormatter $formatter)
  {
    $this->deserializer = $deserializer;
    $this->formatter = $formatter;
  }


  public function getOne(int $id)
  {
   return $this->formatter->format($this->deserializer->deserialize($id));
  }

  public function getAll()
  {
    $path = $this->deserializer->getPath();
    $files = array_diff(scandir($path), array('..', '.'));
    $result = array();
    foreach ($files as $file){
      array_push($result, getOne($file));
    }
    return $result;
  }


}