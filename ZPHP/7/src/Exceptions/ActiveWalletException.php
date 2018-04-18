<?php

namespace Exceptions;


class ActiveWalletException extends \Exception
{
    public function __construct(string $message = 'Your wallet is active!', $code = 0, \Exception $previous = null)
    {
    }
    
}