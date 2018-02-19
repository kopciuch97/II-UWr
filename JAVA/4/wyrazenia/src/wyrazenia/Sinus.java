
package wyrazenia;

 /**
 *
 * 
 * Klasa reprezentujaca operator dwuargumentowy 'dodawanie' sumujacy dwa wyrazenia
 */
   public class Sinus extends Operator1Arg{
        Wyrazenie exp;
        Sinus(Wyrazenie a){
            this.exp=a;
        }
/**Metoda oblicz() nadpisana z abstrakcyjnej klasy Operator1Arg obliczajaca sin wyrazenia
 *@return double
 */ 
        @Override
        public double oblicz(){
            return Math.sin(exp.oblicz());
        }
 /**Metoda toString() nadpisana z abstrakcyjnej klasy Object
 *@return String
 */       
        @Override
        public String toString(){
            return "Sin(" + exp.oblicz()+")";
        }  
    }

