
package wyrazenia;

 /**
 *
 * 
 * Klasa reprezentujaca operator jednoargumentowy 'odwrotnosc' 
 */
public class Odwrotnosc extends Operator1Arg{
        Wyrazenie exp;
        
        Odwrotnosc(Wyrazenie a){
            this.exp=a;
        }
/**Metoda oblicz() nadpisana z abstrakcyjnej klasy Operator1Arg obliczajaca odwrotność wyrażenia
 *@return double
 */
        @Override
        public double oblicz(){
            return 1/exp.oblicz();
        }
 /**Metoda toString() nadpisana z abstrakcyjnej klasy Object
 *@return String
 */ 
        @Override
        public String toString(){
            return "(1/"+exp.oblicz()+")";
        }  
    }
