package ONP.op2arg;

import ONP.Exception.DivisionByZeroONP;
import ONP.Exception.ExceptionONP;

/**
 * Klasa reprezentujaca dzielenie dwoch wartosci
 * @author Szymon
 */
public class Division extends Operator2arg{
            /**
     * Oblicza wartosc wyrazenia klasy
     * @return Wynik
     * @throws ExceptionONP Gdy wystapi blad w obliczeniach 
     */
    @Override
    public double value() throws ExceptionONP{
	if (array[0]==0) throw new DivisionByZeroONP();
        check();
        return array[1]/array[0];
    }
};

