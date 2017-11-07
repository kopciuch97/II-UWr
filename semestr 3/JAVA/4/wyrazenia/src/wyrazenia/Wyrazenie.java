package wyrazenia;

/**
 *
 * @author Szymon
 */
abstract class Wyrazenie {
    
    abstract double oblicz();
  
    public static double sumuj(Wyrazenie... wyr) {
        return 3.14;
    }
    
    public static double pomnoz(Wyrazenie... wyr){
        return 3.2;
    }
}
