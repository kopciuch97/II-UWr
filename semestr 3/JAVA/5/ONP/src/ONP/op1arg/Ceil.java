package ONP.op1arg;

import ONP.Exception.ExceptionONP;

/**
 * Klasa reprezentujaca sufit liczby
 * @author Szymon
 */
public class Ceil extends Operator1arg{
     /**
     * Oblicza wartosc wyrazenia klasy
     * @return Wynik
     * @throws ExceptionONP Gdy wystapi blad w obliczeniach 
     */
    @Override
    public double value() throws ExceptionONP{
        check();
        return Math.ceil(array[0]);
    }
};


