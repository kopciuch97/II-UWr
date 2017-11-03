package geometria;


public class Main
{
        public static void main(String[] args)
        {
System.out.println("---------------- WEKTOR ----------------");
    Wektor v1 = new Wektor(1,2);
    Wektor v2 = new Wektor(3,3);
    Wektor v3 = Wektor.sumuj(v1,v2);

    System.out.println(v1.toString()+ "   "+ v2.toString());
    System.out.println(v3.toString());
System.out.println("---------------- PUNKT ----------------"); 
    Punkt p1 = new Punkt(2,3);
    Punkt p2 = new Punkt(5,6);
    Punkt p3 = new Punkt(4,3);
    System.out.println(p1.toString());
    System.out.println(p2.toString());
    System.out.println(p3.toString());
    p1.obroc(p2,180);
    p2.obroc(p1,90);
    p3.obroc(p1,270);
    System.out.println(p1.toString());
    System.out.println(p2.toString());
    System.out.println(p3.toString());
    System.out.println("---------------- Trojkat ----------------"); 
    Trojkat t1 = new Trojkat(p1,p2,p3);
    System.out.println(t1.toString());
    Prosta pr1 = new Prosta(2,2,4);
    t1.odbij(pr1);
    System.out.println(t1.toString());
            System.out.println("O wektor:");
            t1.przesun(v2);
            System.out.println(t1.toString());
        }
}