package ONP.collection;

import ONP.Exception.IllegalArgumentONP;
import ONP.Exception.ExceptionONP;
import ONP.op0arg.Variable;

/**
 * Klasa List reprezentuje kolekcje lista. 
 * @author Szymon
 */
public class List{

    private Node begin;
    private Node end;

    private boolean search(Variable var){
        Node tmp = begin;
        while (tmp != null) {
            if(tmp.getVar().equals(var)) return true;
            tmp = tmp.getNext();
        }
        return false;
    }
    /**
     * Metoda do znajdowania odpowiadającej wartości double dla podanej zmiennej
     * @param var Nazwa zmiennej
     * @return Wartość zmiennej
     * @throws ExceptionONP Gdy zmienna podana nie istnieje
     */
    public double find(String var) throws ExceptionONP{
        if (!search(new Variable(var,0))) throw new IllegalArgumentONP();
        Node tmp = begin;
        while (tmp != null) {
            if(tmp.getVar().getX().equals(var)) return tmp.getVar().value();
            tmp = tmp.getNext();
        }
        return 0;
    }
    
    public List() {
        begin = null;
        end = null;
    }

    /**
     * Dodaje zmienna do listy
     * @param var Para klucz-wartosc
     * @throws ExceptionONP Jesli podana zmienna juz istnieje
     */
    public void add(Variable var) throws ExceptionONP {
        if (search(var)) throw new IllegalArgumentONP();
        Node wezel = new Node(var, null, null);
        if (empty()) {
            begin = wezel;
            end = wezel;
        } else {
            wezel.setNext(begin);
            begin.setPrevious(wezel);
            begin = wezel;
        }
    }
    /**
     * Usuwa podaja zmienna z listy
     * @param var Para klucz-wartosc
     * @throws ExceptionONP Jesli nie znajduje sie podana zmienna w liscie
     */
    public void del(Variable var) throws ExceptionONP {
        if (!search(var)) throw new IllegalArgumentONP();
        Node tmp = begin;
        while (tmp != null) {
            if (tmp.getVar().equals(var)) {
                if (tmp == begin) {
                    begin = (tmp.getNext());
                    break;
                } else if (tmp == end) {
                    end = (tmp.getPrevious());
                    break;
                } else {
                    (tmp.getPrevious()).setNext(tmp.getNext());
                    (tmp.getNext()).setPrevious(tmp.getPrevious());
                    break;
                }
            }
        }
    }
    /**
     * Aktualizuje zmienna w liscie lub ją dodaje
     * @param r zmienna
     * @throws ExceptionONP 
     */
    public void update(Variable r) throws ExceptionONP{
        if(!search(r)) add(r);
        else{
            del(r);
            add(r);
        }
    }
    /**
     * Usuwa wszystkie zmienne w liscie
     */
    public void delAll(){
        begin=null;
        end=null;
    }
    
    /**
     * Sprawdza czy lista jest pusta
     * @return Zwraca czy lista jest pusta
     */
    public boolean empty() {
        return (begin == null);
    }

    /**
     * Rozmiar listy
     * @return rozmiar listy
     */
    public int size() {
        Node tmp = begin;
        int i = 0;
        while (tmp != null) {
            i++;
            tmp = tmp.getNext();
        }
        return i;
    }
/**
 * Klasa wewnetrzna wezel klasy lista, przechowujaca liste zmiennych Variable
 */
class Node{

    private Variable var;
    private Node next;
    private Node previous;

    public Node() {
        next = null;
        previous = null;
    }

    public Node(Variable var, Node next, Node previous) {
        this.var = var;
        this.next = next;
        this.previous = previous;
    }

    public Variable getVar() {
        return var;
    }

    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    public Node getPrevious() {
        return previous;
    }

    public void setPrevious(Node prev) {
        this.previous = prev;
    }
}

}