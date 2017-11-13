package ONP.op1arg;

import ONP.Exception.ExceptionONP;

/**
 * Klasa obliczajaca sin z dwoch wartosci
 * @author Kamil
 */
public class Sin extends Operator1arg{
     /**
     * Oblicza wartosc wyrazenia klasy
     * @return Wynik
     * @throws ExceptionONP Gdy wystapi blad w obliczeniach 
     */
    @Override
    public double value() throws ExceptionONP {
        check();
        return Math.sin(array[0]);
    }
};


