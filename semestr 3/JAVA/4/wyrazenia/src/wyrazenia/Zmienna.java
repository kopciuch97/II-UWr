
package wyrazenia;

/**
 *
 * @author Szymon
 */
public class Zmienna extends Wyrazenie {
    public static final Zbior setOfVariables;
    public String name;
    static{
        setOfVariables = new Zbior(50);
    }
 
    public Zmienna(String name){
        this.name=name;
    }
    
    public static void addVariable(String key, double value){
        Para para = new Para(key, value);
        setOfVariables.ustal(para);
    }
    @Override
    public double oblicz(){
        return setOfVariables.czytaj(name);
    }
    @Override
    public String toString(){
        return name;
    }
}