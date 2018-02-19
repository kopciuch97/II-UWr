
package wyrazenia;

 /**
 *
 * 
 * Klasa reprezentujaca operator dwuargumentowy 'potegowanie'
 */
  public class Potegowanie extends Operator2Arg{
        Wyrazenie exp1;
        Wyrazenie exp2;
        Potegowanie(Wyrazenie a, Wyrazenie b){
            this.exp1=a;
            this.exp2=b;
        }
/**Metoda oblicz() nadpisana z abstrakcyjnej klasy Operator2Arg potegujaca wyrazenie1 o wykladniku wyrazenia2
 *@return double
 */
        @Override
        public double oblicz(){
            return Math.pow(exp1.oblicz(), exp2.oblicz());
        }
 /**Metoda toString() nadpisana z abstrakcyjnej klasy Object
 *@return String
 */     
        @Override
        public String toString(){
            return "("+exp1+"^"+exp2+")";
        }        
    }