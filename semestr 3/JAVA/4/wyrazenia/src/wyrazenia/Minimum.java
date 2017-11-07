
package wyrazenia;

 /**
 *
 * 
 * Klasa reprezentujaca operator dwuargumentowy 'minimum' zwracajacy mniejsze z dwóch wyrażeń
 */
   public class Minimum extends Operator2Arg{
        Wyrazenie exp1;
        Wyrazenie exp2;
        Minimum(Wyrazenie a, Wyrazenie b){
            this.exp1=a;
            this.exp2=b;
        }
/**Metoda oblicz() nadpisana z abstrakcyjnej klasy Operator2Arg zwracająca mniejsze z dwóch wyrażeń
 *@return double
 */  
        @Override
        public double oblicz(){
            return Math.min(exp1.oblicz(), exp2.oblicz());
        }
 /**Metoda toString() nadpisana z abstrakcyjnej klasy Object
 *@return String
 */ 
        @Override
        public String toString(){
            return "MIN("+exp1+","+exp2+")";
        }        
    }
    