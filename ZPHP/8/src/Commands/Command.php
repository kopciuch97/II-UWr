<?php

namespace Commands;

abstract class Command {
    protected $timestamp;
    abstract public function execute();
}