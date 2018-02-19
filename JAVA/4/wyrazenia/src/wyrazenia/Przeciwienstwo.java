
package wyrazenia;

 /**
 *
 * 
 * Klasa reprezentujaca operator jednoargumentowy 'przeciwienstwo'
 */
public class Przeciwienstwo extends Operator1Arg{
        Wyrazenie exp;
        Przeciwienstwo(Wyrazenie a){
            this.exp=a;
        }
/**Metoda oblicz() nadpisana z abstrakcyjnej klasy Operator1Arg obliczajaca przeciwienstwo wyrazenia
 *@return double
 */
        @Override
        public double oblicz(){
            return -exp.oblicz();
        }
 /**Metoda toString() nadpisana z abstrakcyjnej klasy Object
 *@return String
 */    
        @Override
        public String toString(){
            return "-(" + -exp.oblicz()+")";
        }        
    }
    
    

