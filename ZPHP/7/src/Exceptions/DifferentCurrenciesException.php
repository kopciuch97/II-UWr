<?php

namespace Exceptions;


class DifferentCurrenciesException extends \Exception
{
    public function __construct(string $message = 'Wallet can operate on one currency', $code = 0, \Exception $previous = null)
    {
    }
    
}