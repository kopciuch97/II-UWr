<?php

namespace Exceptions;


class NotEnoughMoneyInWalletException extends \Exception
{
    public function __construct(string $message = 'You have not enough money in your wallet!', $code = 0, \Exception $previous = null)
    {
    }
    
}