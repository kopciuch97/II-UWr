<?php

namespace EventSerializers;

interface EventSerializer{
    public function serialize(array $event);
}