package ONP.Calc;

import ONP.Exception.ExceptionONP;

/**
 * Interfejs Funkcji
 * @author Szymon
 */
public interface IFunction extends ICalculable{
    /**
     * Arnosc funkcji
     * @return arnosc
     */
    public int arity ();
    /**
     * Ilosc brakujacych argumentow
     * @return  
     */
    public int missingArguments ();
    /**
     * Dodaje argument do funkcji
     * @param a
     * @throws ExceptionONP 
     */
    public void addArgument(double a) throws ExceptionONP;
}
