package wyrazenia;

import java.util.Objects;

/**
 * Klasa reprezentujaca Pare jako klucz-wartość
 * @author Szymon
 */
public class Para {

    static void wstaw(Para p) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    //pola:

    /**
     *
     */
    public final String key;
    private double value;

    //konstruktor:

    /**
     *Konstruktor
     * @param key
     * @param value
     */
    public Para(String key, double value) {
        this.key = key;
        this.value = value;
    }
    //getter @return value

    /**
     *getter
     * @return double
     */
    public double getValue(){
        return this.value;
    }
    //setter 

    /**
     *setter
     * @param value
     */
    public void setValue(double value){
        this.value = value;
    }
 /**Metoda toString() nadpisana z abstrakcyjnej klasy Object
 *@return String
 */       
 
    @Override
    public String toString(){
        return "(" + this.key + ", " + this.value + ")" ;
    }
 /**Metoda equals() nadpisana z abstrakcyjnej klasy Object
 *@return bool
 */       
 
    @Override
    public boolean equals(Object obj) {
        if (obj==null){
            return false;
        }
        if (this==obj){
            return true;
        }
        if (this.getClass() != obj.getClass()){
            return false;
        }
        return this.key == ((Para)obj).key;
    }

    @Override
    public int hashCode() {
        int hash = 3;
        hash = 47 * hash + Objects.hashCode(this.key);
        hash = 47 * hash + (int) (Double.doubleToLongBits(this.value) ^ (Double.doubleToLongBits(this.value) >>> 32));
        return hash;
    }
    
    
}
