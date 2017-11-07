/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package wyrazenia;

/**
 *
 * @author Szymon
 */
 class Odwrotnosc extends Operator1Arg{
        Wyrazenie exp;
        
        public Odwrotnosc(Wyrazenie a){
            this.exp=a;
        }

        @Override
        public double oblicz(){
            return 1/exp.oblicz();
        }

        @Override
        public String toString(){
            return "(1/"+exp.oblicz()+")";
        }  
    }
