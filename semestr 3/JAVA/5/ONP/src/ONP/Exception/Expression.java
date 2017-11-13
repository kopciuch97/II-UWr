package ONP.Exception;

import ONP.op1arg.Abs;
import ONP.op1arg.Acot;
import ONP.op1arg.Atan;
import ONP.op1arg.Ceil;
import ONP.op1arg.Cos;
import ONP.op1arg.Exp;
import ONP.op1arg.Floor;
import ONP.op1arg.Frac;
import ONP.Calc.Function;
import ONP.collection.List;
import ONP.op1arg.Ln;
import ONP.op0arg.Number;
import ONP.Calc.Operand;
import ONP.collection.Queue;
import ONP.op1arg.Sgn;
import ONP.op1arg.Sin;
import ONP.collection.Stack;
import ONP.Calc.Symbol;
import ONP.op0arg.Variable;
import ONP.op0arg.E;
import ONP.op0arg.Pi;
import ONP.op2arg.Min;
import ONP.op2arg.Subtraction;
import ONP.op2arg.Multiplication;
import ONP.op2arg.Log;
import ONP.op2arg.Addition;
import ONP.op2arg.Pow;
import ONP.op2arg.Division;
import ONP.op2arg.Max;
import java.util.regex.Pattern;

/**
 * Klasa Expression jest to wyrazenie reprezentowane w posiaci ONP. Służy do obliczen takich wyrazen. 
 * @author Szymon
 * 
 */
public class Expression {
    private final Queue queue; // kolejka symboli wyrażenia ONP (elementy typu Symbol)
    private final Stack stack; // stos z wynikami pośrednimi obliczeń (elementy typu double)
    private final List var; // lista zmiennych czyli pary klucz-wartość (String-double)
    private double result;

    /**
     * Wynik wyrazenia
     * @return Zwraca wynik wyrazenia 
     */
    public double getResult() {
        return result;
    }
    
    /**
     * Konstruktor inicjalizujacy zmienne, parsuje wyrazenie i wylicza jego wartosc
     * @param onp Przyjmuje wyrazenie onp w stringu
     * @throws ExceptionONP  jesci napotka blad w wyrazeniu ONP wyrzuca go dalej
     */
    public Expression (String onp) throws ExceptionONP
    {
        var=new List();
        queue=new Queue();
        stack=new Stack();
        parser(onp);
        countONP();
        result=getValue();
        
    }
     /**
     * Konstruktor inicjalizujacy zmienne, parsuje wyrazenie i wylicza jego wartosc. 
     * @param onp Przyjmuje wyrazenie onp w stringu
     * @param zm Przyjmuje liste zmiennych
     * @throws ExceptionONP  jesci napotka blad w wyrazeniu ONP wyrzuca go dalej
     */   
    public Expression (String onp, List zm) throws ExceptionONP
    {
        queue=new Queue();
        stack=new Stack();
        var=zm;
        parser(onp);
        countONP();
        result=getValue();
    }
       
    private void parser(String onp) throws ExceptionONP{
        String symbols[];
        symbols = onp.split(" ");
        for (String symbol : symbols) {
            if(Pattern.matches("(?i)acot", symbol)) queue.push(new Acot());
            else if(Pattern.matches("(?i)abs", symbol))queue.push(new Abs());
            else if(Pattern.matches("(?i)floor", symbol))queue.push(new Floor());
            else if(Pattern.matches("(?i)sgn", symbol))queue.push(new Sgn());
            else if(Pattern.matches("(?i)pow", symbol))queue.push(new Pow());
            else if(Pattern.matches("(?i)max", symbol))queue.push(new Max());
            else if(Pattern.matches("(?i)min", symbol))queue.push(new Min());
            else if(Pattern.matches("(?i)log", symbol))queue.push(new Log());
            else if(Pattern.matches("\\*", symbol))queue.push(new Multiplication());
            else if(Pattern.matches("\\/", symbol))queue.push(new Division());
            else if(Pattern.matches("\\-", symbol))queue.push(new Subtraction());
            else if(Pattern.matches("\\+", symbol))queue.push(new Addition());
            else if(Pattern.matches("(?i)ceil", symbol))queue.push(new Ceil());
            else if(Pattern.matches("(?i)frac", symbol))queue.push(new Frac());
            else if(Pattern.matches("(?i)sin", symbol))queue.push(new Sin());
            else if(Pattern.matches("(?i)cos", symbol))queue.push(new Cos());
            else if(Pattern.matches("(?i)atan", symbol))queue.push(new Atan());
            else if(Pattern.matches("(?i)ln", symbol))queue.push(new Ln());
            else if(Pattern.matches("(?i)exp", symbol))queue.push(new Exp());
            else if(Pattern.matches("(?i)pi", symbol))queue.push(new Pi());
            else if(Pattern.matches("(?i)e", symbol))queue.push(new E());
            else if(Pattern.matches("[+-]?[0-9]+(\\.[0-9]+)?", symbol))queue.push(new Number(Double.parseDouble(symbol))); 
            else {
                double l=var.find(symbol);
                 queue.push(new Variable(symbol,l));
            }
        }
    }
    
    private void countONP() throws ExceptionONP{
        Symbol w;
        do {
            w=queue.pop();
            if(w instanceof Function){
                if (stack.size()<((Function) w).arity()) throw new IncorrectExpressionONP();
                while (((Function) w).missingArguments()>0){
                    ((Function) w).addArgument(stack.pop());
                }
                stack.push(w.value());
            }
            else if(w instanceof Operand){
                stack.push(w.value());
            }
	}while(queue.size()>0);
        if(stack.size()!=1) {
            throw new IncorrectExpressionONP();
        }
    }
    
    private double getValue() throws ExceptionONP{
        if(stack.size()!=1) {
            if (stack.size()>1) throw new IncorrectExpressionONP();
            if (stack.size()<1) throw new IncorrectExpressionONP("No result");
        }        
        return stack.pop();
    }  
}
