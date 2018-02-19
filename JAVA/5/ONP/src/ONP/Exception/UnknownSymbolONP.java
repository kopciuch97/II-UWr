package ONP.Exception;

/**
 * Klasa Wyjatek wyrazenia ONP zostaje wyrzocy gdy symbol w wyrazeniu jest nie znany 
 * @author Szymon
 */
public class UnknownSymbolONP extends ExceptionONP{
    
    public UnknownSymbolONP (String x){
        super(x);
    }

    public UnknownSymbolONP() {
        this("Unknown Symbol in the expression ONP");
    }
   
    @Override
    public String toString ()
    {
        return "Unknown Symbol in the expression ONP";
    }
}
