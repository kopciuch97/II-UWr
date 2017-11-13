package ONP.Exception;

/**
 * Klasa Wyjatek wyrazenia ONP
 * @author Szymon
 */
public class ExceptionONP extends Exception {

    public ExceptionONP (String x)
    {
        super(x);
    }

    public ExceptionONP() {
        this("It was thrown exception in the expression ONP");
    }
   
    @Override
    public String toString ()
    {
        return "It was thrown exception in the expression ONP";
    }
}
