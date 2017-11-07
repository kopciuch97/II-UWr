package wyrazenia;

/**
 *
 * @author Szymon
 */
public class Stala extends Wyrazenie {

    /**
     *
     */
    public double value;
    
    Stala(double value){
        this.value = value;
    }
    
    /**
     *
     * @return
     */
    @Override
    public double oblicz(){
        return value;
    }
    
    @Override
    public String toString(){
        return String.valueOf(value);
    }
    
    
    
}
