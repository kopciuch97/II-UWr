<?php
namespace Exceptions;
class InactiveWalletException extends \Exception{
    
    /**
     * InactiveWalletException constructor.
     */
    public function __construct(string $message = 'Your wallet is inactive!', $code = 0, \Exception $previous = null)
    {
    }
    
}