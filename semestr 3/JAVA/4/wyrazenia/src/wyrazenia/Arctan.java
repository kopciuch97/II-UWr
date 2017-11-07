
package wyrazenia;

/**
 *
 * @author Szymon
 * Klasa reprezentujaca operator jednoargumentowy Arctan
 */
    class Arctan extends Operator1Arg{
        Wyrazenie exp;
        public Arctan(Wyrazenie a){
            this.exp=a;
        }
/**Metoda oblicz() nadpisana z abstrakcyjnej klasy Operator1Arg obliczajaca Arctan wyrazenia
 *@return double
 */
        @Override
        public double oblicz(){
            return Math.atan(exp.oblicz());
        }
/**Metoda toString nadpisana z klasy Object
*@return String
*/
        @Override
        public String toString(){
            return "Arctan(" + exp.oblicz()+")";
        }  
    }

