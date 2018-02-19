package ONP.op1arg;

import ONP.op0arg.Operator0arg;

/**
 * Klasa reprezentujaca funkcje jedno-argumentowe
 * @author Szymon
 */
public abstract class Operator1arg extends Operator0arg{
     /**
     * Zwraca arnosc funkcji
     * @return Arnosc
     */
    @Override
    public int arity (){
        return 1;
    }
};

