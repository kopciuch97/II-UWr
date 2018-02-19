
package wyrazenia;

 /**
 *
 * 
 * Klasa reprezentujaca operator dwuargumentowy 'maksimum' zwracajacy wieksze z dwóch wyrażeń
 */
   public class Maksimum extends Operator2Arg{
        Wyrazenie exp1;
        Wyrazenie exp2;
        Maksimum(Wyrazenie a, Wyrazenie b){
            this.exp1=a;
            this.exp2=b;
        }

/**Metoda oblicz() nadpisana z abstrakcyjnej klasy Operator2Arg zwracająca wieksze z dwóch wyrażeń
 *@return double
 */   
        @Override
        public double oblicz(){
            return Math.max(exp1.oblicz(), exp2.oblicz());
        }

 /**Metoda toString() nadpisana z abstrakcyjnej klasy Object
 *@return String
 */       
        @Override
        public String toString(){
            return "MAX("+exp1+","+exp2+")";
        }        
    }