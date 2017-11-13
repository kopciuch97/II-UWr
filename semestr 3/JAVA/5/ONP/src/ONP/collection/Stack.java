package ONP.collection;

import ONP.Exception.EmptyStackONP;
import ONP.Exception.ExceptionONP;

/**
 * Klasa implementujaca kolekcje Stos
 * @author Szymon
 */
public class Stack {
    private Elem start;
 
    public Stack(){
        start=null;
    }
    /**
     * Wstawia wartosc do stosu
     * @param x Wartosc 
     */
    public void push(double x){
        Elem temp = new Elem(x,start);
        start=temp;
    }
    /**
     * Wyciaga wartosc z strosu
     * @return Wartosc
     * @throws ExceptionONP Gdy wystapi blad
     */
    public double pop() throws ExceptionONP{
        if (start==null) {
            throw new EmptyStackONP();
        }
        double d=start.getVal();
        start = start.getNext();
        return d;
    }
    /**
     * Metoda zwracajaca rozmiar stosu
     * @return Rozmiar
     */
    public int size(){
        if(start!=null){
            Elem temp = start;
            int i=0;
            while(temp!=null){
                i++;
                temp = temp.getNext();
            }
            return i;
        }
        return 0;
    }
    /**
     * Klasa wewnetrzna implementujaca wezel 
     */
    class Elem {
        double val;
        Elem next;
 
        public Elem(double x, Elem n){
            next=n;
            val=x;
        }

        public Elem getNext(){
            return next;
        }
 
        public double getVal(){
            return val;
        }
    }
}
 
