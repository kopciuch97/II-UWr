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
    class Cosinus extends Operator1Arg{
        Wyrazenie exp;
        public Cosinus(Wyrazenie a){
            this.exp=a;
        }

        @Override
        public double oblicz(){
            return Math.cos(exp.oblicz());
        }

        @Override
        public String toString(){
            return "Cos(" + exp.oblicz()+")";
        }  
    }

