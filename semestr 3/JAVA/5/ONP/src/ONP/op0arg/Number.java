package ONP.op0arg;

import ONP.Calc.Operand;

/**
 * Klasa reprezentujaca liczbe
 * @author Szymon
 */
public class Number extends Operand{
    private final double val;
    public Number (double x){ val=x; }
    /**
     * Zwraca wartosc liczby
     * @return Liczba
     */
    @Override
    public double value(){ return val; }
};

