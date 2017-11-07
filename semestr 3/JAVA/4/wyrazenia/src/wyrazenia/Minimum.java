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
    class Minimum extends Operator2Arg{
        Wyrazenie exp1;
        Wyrazenie exp2;
        public Minimum(Wyrazenie a, Wyrazenie b){
            this.exp1=a;
            this.exp2=b;
        }

        @Override
        public double oblicz(){
            return Math.min(exp1.oblicz(), exp2.oblicz());
        }

        @Override
        public String toString(){
            return "MIN("+exp1+","+exp2+")";
        }        
    }
    