/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package wyrazenia;

 /**
 *
 * 
 * Klasa reprezentujaca operator dwuargumentowy 'mnozenie' zwracający iloczyn dwóch wyrażeń
 */
   public class Mnozenie extends Operator2Arg{
            Wyrazenie exp1;
            Wyrazenie exp2;
            Mnozenie(Wyrazenie a, Wyrazenie b){
                this.exp1=a;
                this.exp2=b;
            }
/**Metoda oblicz() nadpisana z abstrakcyjnej klasy Operator2Arg obliczajaca iloczyn dwóch wyrażeń
 *@return double
 */
            @Override
            public double oblicz(){
                return exp1.oblicz() * exp2.oblicz();
            }
 /**Metoda toString() nadpisana z abstrakcyjnej klasy Object
 *@return String
 */ 
            @Override
            public String toString(){
                return "("+exp1+"*"+exp2+")";
        }        
    }
    