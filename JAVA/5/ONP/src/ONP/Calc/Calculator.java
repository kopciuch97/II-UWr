package ONP.Calc;


import ONP.op0arg.Variable;
import ONP.collection.List;
import ONP.Exception.Expression;
import ONP.Exception.ExceptionONP;
import java.util.Scanner;
import java.util.regex.Pattern;

/**
 * Program do obliczenia wyrazen ONP
 * @author Szymon
 */
public class Calculator {
    static List var=new List();
    
    private static double calc(String c) throws ExceptionONP{
        String symbols[];
        symbols = c.split(" ");
        String onp="";
        int i;
        for (i=1;i<=symbols.length;i++) {
            if(symbols.length>i && symbols[i].equals("=")){
                break;
            }
            else if(!symbols[i-1].equals("calc")) onp=onp+symbols[i-1]+" ";
        }
        Expression w=new Expression(onp,var);
        for (;i<symbols.length;i++) {
            if(symbols[i].equals("=")){
                var.update(new Variable(symbols[i-1],w.getResult()));
            }
        }
        
        return w.getResult();
    }
    
    private static void clear(String c) throws ExceptionONP{
        String symbols[];
        symbols= c.split(" ");
        boolean all=true;
        for (String symbol : symbols) {
            if (!symbol.equals("clear")) {
                var.del(new Variable(symbol,0));
                all=false;
                System.out.println("Deleted "+symbol);
            }
        }
        if (all) var.delAll();
        System.out.println("Deleted all symbols");
    } 
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String command;
        do{
            try{
                command=sc.nextLine();
                if(Pattern.matches("calc .*", command)) {                                      
                    System.out.println(calc(command));
                }
                else if(Pattern.matches("clear .*", command)) {
                    clear(command);
                }
                if(Pattern.matches("exit", command)) {
                    break;
                }
                else{
                    assert Pattern.matches("(exit)?(clear .*)?(calc .*)?", command): "Here is error";
                }
            }catch(ExceptionONP ex){
                ex.printStackTrace();
            }catch (AssertionError a){
                a.printStackTrace();
            }
            
        }while(true);
         System.out.println("THE END");
    }
}
