package ONP.Exception;

/**
 * Klasa Wyjatek wyrazenia ONP, zostaje wyrzucony gdy argument jest niepoprawny
 * @author Szymon
 */
public class IllegalArgumentONP extends ExceptionONP{
    public IllegalArgumentONP (String x){
        super(x);
    }

    public IllegalArgumentONP() {
        this("Illegal Argument in the expression ONP");
    }
   
    @Override
    public String toString ()
    {
        return "Illegal Argument in the expression ONP";
    }
}
