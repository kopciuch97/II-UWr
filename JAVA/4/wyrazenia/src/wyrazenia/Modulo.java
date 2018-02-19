
package wyrazenia;

 /**
 *
 * 
 * Klasa reprezentujaca operator dwuargumentowy 'modulo' 
 */
    public class Modulo extends Operator2Arg{
        Wyrazenie exp1;
        Wyrazenie exp2;
        Modulo(Wyrazenie a, Wyrazenie b){
            this.exp1=a;
            this.exp2=b;
        }
/**Metoda oblicz() nadpisana z abstrakcyjnej klasy Operator2Arg zwracający resztę z dzielenia wyrażenia1 przez wyrażenie2
 *@return double
 */
        @Override
        public double oblicz(){
            return exp1.oblicz() % exp2.oblicz();
        }
 /**Metoda toString() nadpisana z abstrakcyjnej klasy Object
 *@return String
 */ 
        @Override
        public String toString(){
            return "("+exp1+" mod "+exp2+")";
        }        
    }
