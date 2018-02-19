
package wyrazenia;

/**
 *
 * 
 * Klasa reprezentujaca operator jednoargumentowy Arctan
 */
    public class Arctan extends Operator1Arg{
        Wyrazenie exp;
        Arctan(Wyrazenie a){
            this.exp=a;
        }
/**Metoda oblicz() nadpisana z abstrakcyjnej klasy Operator1Arg obliczajaca Arctan wyrazenia
 *@return double
 */
        @Override
        public double oblicz(){
            return Math.atan(exp.oblicz());
        }
/**Metoda toString nadpisana z klasy Objec
* @return String*/
        @Override
        public String toString(){
            return "Arctan(" + exp.oblicz()+")";
        }  
    }

