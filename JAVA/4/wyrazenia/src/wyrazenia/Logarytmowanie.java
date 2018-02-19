
package wyrazenia;

 /**
 *
 * 
 * Klasa reprezentujaca operator dwuargumentowy 'logarytmowanie'
 */
    public class Logarytmowanie extends Operator2Arg{
        Wyrazenie exp1;
        Wyrazenie exp2;
        Logarytmowanie(Wyrazenie a, Wyrazenie b){
            this.exp1=a;
            this.exp2=b;
        }

/**Metoda oblicz() nadpisana z abstrakcyjnej klasy Operator2Arg obliczajaca Logarytm o podstawie wyrazenia z wyrazenia wyrazenia
 *@return double
 */
 
        @Override
        public double oblicz(){
            return Math.log(exp1.oblicz())/Math.log(exp2.oblicz());
        }

/**Metoda toString() nadpisana z abstrakcyjnej klasy Object
 *@return String
 */  
        @Override
        public String toString(){
            return "Log"+exp1+"("+exp2+")";
        }        
    }