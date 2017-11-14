package ONP.collection;

import ONP.Exception.NoElementsONP;
import ONP.Exception.ExceptionONP;
import ONP.Calc.Symbol;

/**
 * Klasa reprezentujaca kolekcjie kolejka
 * @author Szymon
 */
public class Queue {    
    private Elem first, last;
 
    public Queue(){
        first = last = null;
    }
   /**
    * Wstawienie do kolejki
    * @param x Symbol
    */ 
    public void push(Symbol x){
        Elem temp = new Elem(x);
        if(first==null){
           first = last = temp;
        }
        else {
            last.setNext(temp);
            last = temp;
        }
    }
    /**
     * Wyciagniecie z kolejki
     * @return zwraca Symbol z kolejki
     * @throws ExceptionONP 
     */
    public Symbol pop() throws ExceptionONP{
        if(first==null){
            throw new NoElementsONP();
        }
        Symbol tmp=first.getVal();
        if(first.getNext()==null){
            last=null;
        }
        first = first.getNext();
        return tmp;
    }
    /**
     * Zwraca rozmiar kolejki
     * @return Rozmiar kolejki
     */
    public int size(){
        if(first!=null){
            int licznik=0;
            Elem temp = first;
            while(temp!=null){
                licznik++;
                temp=temp.getNext();
            }
        return licznik;
        }
    return 0;
    }
/**
 * Klasa reprezentujaca wezel kolejki
 */
class Elem {
    private Symbol val;
    private Elem next;
 
    public Elem(Symbol x){
        val = x;
        next = null;
    }
 
    public void setNext(Elem e){
        next = e;
    }
 
    public Elem getNext(){
        return next;
    }
 
    public Symbol getVal(){
        return val;
    }
};
};


 