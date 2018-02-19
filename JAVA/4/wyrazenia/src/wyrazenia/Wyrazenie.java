package wyrazenia;

/**
 *
 * @author Szymon
 */
abstract class Wyrazenie {
    
    abstract double oblicz();
  
    public static double sumuj(Wyrazenie... wyr) {
        double suma = 0;
        for(Wyrazenie exp:wyr){
            suma+=exp.oblicz();
        }
        return suma;
    }
    
    public static double pomnoz(Wyrazenie... wyr){
        double iloczyn = 0;
        for(Wyrazenie exp:wyr){
            iloczyn*=exp.oblicz();
        }
        return iloczyn;
    }
}
