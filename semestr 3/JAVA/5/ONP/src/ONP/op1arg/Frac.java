package ONP.op1arg;

import ONP.Exception.ExceptionONP;

/**
 * Klasa reprezentujaca czesc ulamkowa
 * @author Szymon
 */
public class Frac extends Operator1arg{
            /**
     * Oblicza wartosc wyrazenia klasy
     * @return Wynik
     * @throws ExceptionONP Gdy wystapi blad w obliczeniach 
     */
    @Override
    public double value() throws ExceptionONP {
        check();
        double c;
        return array[0]-Math.floor(array[0]);
    }
};

