
package wyrazenia;

 /**
 *
 * 
 * Klasa reprezentujaca operator dwuargumentowy 'dzielenie' dzielący dwa wyrazenia
 */
    public class Dzielenie extends Operator2Arg{
        Wyrazenie exp1;
        Wyrazenie exp2;
        
        Dzielenie(Wyrazenie a, Wyrazenie b){
            this.exp1=a;
            this.exp2=b;
        }
        
 /**Metoda oblicz() nadpisana z abstrakcyjnej klasy Operator2Arg obliczajaca iloraz dwóch wyrażeń
 *@return double
 */
        @Override
        public double oblicz(){
            return exp1.oblicz() / exp2.oblicz();
        }

/**Metoda toString() nadpisana z abstrakcyjnej klasy Object
 *@return String
 */ 
        @Override
        public String toString(){
            return "("+exp1+"/"+exp2+")";
        }        
    }