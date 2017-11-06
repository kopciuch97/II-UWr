package wyrazenia;

import java.util.Objects;

/**
 * Klasa reprezentujaca Pare jako klucz-wartość
 * @author Szymon
 */
public class Para {
    //pola:
    public final String key;
    private double value;

    //konstruktor:
    public Para(String key, double value) {
        this.key = key;
        this.value = value;
    }
    //getter @return value
    public double getValue(){
        return this.value;
    }
    //setter 
    public void setValue(double value){
        this.value = value;
    }
    //toString override
    @Override
    public String toString(){
        return "(" + this.key + ", " + this.value + ")" ;
    }
    //equals override
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
