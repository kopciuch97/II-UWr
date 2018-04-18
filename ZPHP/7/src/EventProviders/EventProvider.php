<?php

namespace EventProviders;


interface EventProvider{
    public function provideEvents() : array;
}