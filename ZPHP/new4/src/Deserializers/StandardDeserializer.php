<?php
namespace src\Deserializers;



class StandardDeserializer implements IDeserializer  {
  private $path;

  /**
   * StandardDeserializer constructor.
   * @param $path
   */
  public function __construct($path)
  {
    $this->path = $path;
  }

  public function deserialize(int $id)
  {
    return unserialize($this->path . $id);
  }

  public function getPath()
  {
    return $this->path;
  }


}