package ONP.op1arg;

import ONP.Exception.DivisionByZeroONP;
import ONP.Exception.ExceptionONP;

/**
 * Klasa reprezentujaca ArcusTangens
 * @author Szymon
 */
public class Acot extends Operator1arg{
         /**
     * Oblicza wartosc wyrazenia klasy
     * @return Wynik
     * @throws ExceptionONP Gdy wystapi blad w obliczeniach 
     */
    @Override
    public double value() throws ExceptionONP{
        check();
        if(Math.atan(array[0])==0) throw new DivisionByZeroONP();
        return 1/Math.atan(array[0]);
    }
};


