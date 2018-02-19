package ONP.op2arg;

import ONP.Exception.ExceptionONP;

/**
 * Klasa reprezentujaca dodawanie dwoch wartosci
 * @author Szymon
 */
public class Addition extends Operator2arg{
         /**
     * Oblicza wartosc wyrazenia klasy
     * @return Wynik
     * @throws ExceptionONP Gdy wystapi blad w obliczeniach 
     */
    @Override
    public double value() throws ExceptionONP{
        check();
        return array[1]+array[0];
    }
};


