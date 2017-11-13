package ONP.op2arg;

import ONP.Exception.ExceptionONP;

/**
 * Klasa reprezentujaca operacje wyboru max z dwoch wartosci
 * @author Szymon
 */
public class Max extends Operator2arg{
        /**
     * Oblicza wartosc wyrazenia klasy
     * @return Wynik
     * @throws ExceptionONP Gdy wystapi blad w obliczeniach 
     */
    @Override
    public double value() throws ExceptionONP {
        check();
        return Math.max(array[0],array[1]);
    }
};

