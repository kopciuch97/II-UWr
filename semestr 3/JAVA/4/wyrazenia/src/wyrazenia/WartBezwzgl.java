
package wyrazenia;

 /**
 *
 * 
 * Klasa reprezentujaca operator jednoargumentowy 'Wartoscbezwgledna'
 */
public class WartBezwzgl extends Operator1Arg{
        Wyrazenie exp;
        WartBezwzgl(Wyrazenie a){
            this.exp=a;
        }
/**Metoda oblicz() nadpisana z abstrakcyjnej klasy Operator1Arg zwracajaca modul wyrazenia
 *@return double
 */
        @Override
        public double oblicz(){
            if (exp.oblicz()<0)
                return -exp.oblicz();
            else
                return exp.oblicz();
        }
 /**Metoda toString() nadpisana z abstrakcyjnej klasy Object
 *@return String
 */ 
        @Override
        public String toString(){
            return "|"+exp.oblicz()+"|";
        }  
    }