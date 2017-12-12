package ONP.op1arg;

import ONP.Exception.ExceptionONP;

/**
 * Klasa reprezentujaca ArcusTangens
 * @author Szymon
 */
public class Atan extends Operator1arg{
         /**
     * Oblicza wartosc wyrazenia klasy
     * @return Wynik
     * @throws ExceptionONP Gdy wystapi blad w obliczeniach 
     */
    @Override
    public double value() throws ExceptionONP{
        check();
        return Math.atan(array[0]);
}
};

