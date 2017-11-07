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
class WartBezwzgl extends Operator1Arg{
        Wyrazenie exp;
        public WartBezwzgl(Wyrazenie a){
            this.exp=a;
        }

        @Override
        public double oblicz(){
            if (exp.oblicz()<0)
                return -exp.oblicz();
            else
                return exp.oblicz();
        }

        @Override
        public String toString(){
            return "|"+exp.oblicz()+"|";
        }  
    }