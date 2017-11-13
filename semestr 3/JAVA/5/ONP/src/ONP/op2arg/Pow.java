package ONP.op2arg;

import ONP.Exception.ExceptionONP;

/**
 * Klasa reprezentujaca potegowanie liczb
 * @author Szymon
 */
public class Pow extends Operator2arg{
     /**
     * Oblicza wartosc wyrazenia klasy
     * @return Wynik
     * @throws ExceptionONP Gdy wystapi blad w obliczeniach 
     */
    @Override
    public double value() throws ExceptionONP{
        check();
        return Math.pow(array[1],array[0]);
    }
};


