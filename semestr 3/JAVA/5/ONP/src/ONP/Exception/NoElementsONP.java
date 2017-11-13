package ONP.Exception;

/**
 * Klasa Wyjatek wyrazenia ONP gdy brak elementow w kolekcji
 * @author Szymon
 */
public class NoElementsONP extends ExceptionONP{
    public NoElementsONP (String x){
        super(x);
    }

    public NoElementsONP() {
        this("No Elements in the collection");
    }
   
    @Override
    public String toString ()
    {
        return "No Elements in the collection";
    }
}
