package ONP.op1arg;

import ONP.Exception.ExceptionONP;

/**
 * Klasa reprezentujaca exp
 * @author Szymon
 */
public class Exp extends Operator1arg{
            /**
     * Oblicza wartosc wyrazenia klasy
     * @return Wynik
     * @throws ExceptionONP Gdy wystapi blad w obliczeniach 
     */
    @Override
    public double value() throws ExceptionONP{
        check();
        return Math.exp(array[0]);
    }
};

