package ONP.op2arg;

import ONP.op1arg.Operator1arg;

/**
 * Klasa reprezentujaca funkcje dwu-argumentowe
 * @author Szymon
 */
public abstract class Operator2arg extends Operator1arg{
    /**
     * Zwraca arnosc funkcji
     * @return Arnosc
     */
    @Override
    public int arity(){
        return 2;
    }
};

