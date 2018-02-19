package ONP.Calc;

import ONP.Exception.ExceptionONP;

/**
 * Interfejs ICalculable
 * @author Szymon
 */
public interface ICalculable {
    /**
     * Metoda obliczajaca wartosc wyrazenia ONP
     * @return Zwraca wynik
     * @throws ExceptionONP Wyrzuca wyjatek gdy wystapi bład w wyrazeniu 
     */
    public double value () throws ExceptionONP;
}

