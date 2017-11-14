package ONP.Calc;

import ONP.Exception.IllegalArgumentONP;
import ONP.Exception.ExceptionONP;
import ONP.Calc.IFunction;
import ONP.Calc.Symbol;

/**
 * Klasa funckja reprezentujaca funckje wyrazenia onp
 * @author Szymon
 */
public abstract class Function extends Symbol implements IFunction{   
    protected int n=0;
    protected double[] array = new double[arity()];
/**
 * Zwraca liczbe brakujacych argumentow
 * @return 
 */
    @Override
    public int missingArguments (){
        return arity()-n;
    }
   /**
    * Dodaje argumenty
    * @param a 
    */
    @Override
    public void addArgument(double a){
        array[n]= a;
        n++;
    }
/**
 * Sprawdza czy cos znajduje sie w tablicy argumentow
 * @throws ExceptionONP 
 */
    public void check() throws ExceptionONP{
        if(n==0) throw new IllegalArgumentONP("too few arguments");
    } 
};

