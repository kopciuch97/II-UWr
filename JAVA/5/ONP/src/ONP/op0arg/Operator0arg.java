package ONP.op0arg;

import ONP.Calc.Function;

/**
 * Klasa reprezentujaca funkcje zero-argumentowe
 * @author Szymon
 */
public abstract class Operator0arg extends Function{
     /**
     * Zwraca arnosc funkcji
     * @return Arnosc 
     */
    @Override
    public int arity (){
        return 0;
    }
};


