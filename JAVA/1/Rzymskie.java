
/**
 *
 * @author Szymon
 */



public class Rzymskie {
    private static final String[] roman = {
       "|MV|", "M", "CM", "D", "CD", "C","XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    private static final  int[] arab = {
        4000, 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    public static void main(String[] args){
        for(String tab: args){
            try{
                int var = new Integer(tab);
                if(var<=0 || var>=5000){
                    throw new IllegalArgumentException("liczba " + var + " spoza zakresu 1-4999");

                }
                else{
                    String res = "";
                    int index = 0;

                    while(var>0){
                        if(var>=arab[index])
                        {
                            res+=roman[index];
                            var-=arab[index];
                        }
                        else
                        {
                            index += 1;
                        }
                    }
                    System.out.println(tab+" ---> "+res);
                }
            }
            catch(NumberFormatException e){
                System.err.println(tab + " ---> Bledny typ, podaj typ calkowitoliczbowy");
            }
            catch(IllegalArgumentException e){
                System.err.println(tab +" ---> Podaj liczbe z zakresu 1-4999");
            }
            }
        }
           
};

//java -classpath . rzymskie.Rzymskie args