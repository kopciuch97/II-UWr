<?php

interface MoneyFormatter
{
    /**
     * @param Money $obj
     * @return string
     */
    public function format(Money $obj): string;
}

class Money
{

    private $value;
    private $currency;

    /**
     * Money constructor.
     * @param  float $value
     * @param string $currency
     */
    public function __construct(float $value, string $currency)
    {
        $this->value = $value;
        $this->currency = $currency;
    }


    /**
     * @param Money $obj
     * @throws Exception
     */
    public function add(Money $obj): void
    {
        if ($this->currency == $obj->getCurrency()) {
            $this->value += $obj->getValue();
        } else {
            throw new Exception("Adding objects currencies must be equal!");
        }
    }

    /**
     * @return string
     */
    public function getCurrency(): string
    {
        return $this->currency;
    }

    /**
     * @return float
     */
    public function getValue(): float
    {
        return $this->value;
    }

    /**
     * @param float $value
     * @throws Exception
     */
    public function setValue(float $value): void
    {

        $this->value = $value;

    }

    /**
     * @param Money $obj
     * @throws Exception
     */
    public function subtract(Money $obj): void
    {
        if ($this->currency == $obj->getCurrency() && $this->value >= $obj->getValue()) {
            $this->value -= $obj->getValue();
        } else {
            throw new Exception("Subtracting objects curriencies must be equal!");
        }
    }

    /**
     * @param float $value
     * @throws Exception
     */
    public function multiple(float $value): void
    {
        $this->value *= $value;
    }

    /**
     * @param float $value
     * @throws Exception
     */
    public function divide(float $value): void
    {
        $this->value /= $value;
    }
}

class CustomFormatter implements MoneyFormatter
{

    private $thousands_sep;
    private $odd_money_sep;

    /**
     * CustomFormatter constructor.
     * @param string $thousands_sep
     * @param string $odd_money_sep
     */
    public function __construct(string $thousands_sep, string $odd_money_sep)
    {
        $this->thousands_sep = $thousands_sep;
        $this->odd_money_sep = $odd_money_sep;
    }

    /**
     * @param Money $obj
     * @return string
     */
    public function format(Money $obj): string
    {
        $result = number_format($obj->getValue(), 2, $this->odd_money_sep, $this->thousands_sep);
        $currency = $obj->getCurrency();
        return $result . " " . $currency;
    }
}

$howmanyargs = $_SERVER['argc'];
$args = $_SERVER['argv'];

try {
    $curr = $args[1];
    $mainobj = new Money(0, $curr);
    $formatter = new CustomFormatter(" ", ",");

    for ($i = 2; $i < $howmanyargs; $i++) {
        $obj = new Money($args[$i], $curr);
        $mainobj->add($obj);
    }
    echo $formatter->format($mainobj) . PHP_EOL;


} catch (Exception $e) {
    echo "Caught exception at line: " . $e->getLine() . PHP_EOL;
    echo "Message: " . $e->getMessage();
}
