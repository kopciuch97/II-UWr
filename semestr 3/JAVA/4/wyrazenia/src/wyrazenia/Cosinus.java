
package wyrazenia;

/**
 *
 * Klasa reprezentujaca operator jesnoargumentowy Cosinus
 */
    public class Cosinus extends Operator1Arg{
        Wyrazenie exp;
        Cosinus(Wyrazenie a){
            this.exp=a;
        }
/**Metoda oblicz() nadpisana z abstrakcyjnej klasy Operator1Arg obliczajaca cosinus wyrazenia
 *@return double
 */
        @Override
        public double oblicz(){
            return Math.cos(exp.oblicz());
        }
/**Metoda toString() nadpisana z klasy Object
 *@return String
 */
        @Override
        public String toString(){
            return "Cos(" + exp.oblicz()+")";
        }  
    }

