package wyrazenia;
class Main{
public static void main(String[] args){
    Wyrazenie w = new Dodawanie(
        new Stala(7),
        new Mnozenie(
            new Stala(3),
                new Stala(5)
                )
        );
    System.out.println(w.oblicz());   

    
    }
}
