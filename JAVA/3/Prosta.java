package geometria;
public final class Prosta{

    public final double a, b, c;

    public Prosta (double a, double b, double c){
        this.a =a;
        this.b =b;
        this.c =c;
    }

    @Override
    public String toString(){
        return "Prosta - " + a +"x + "+b+"y + "+c+" = 0";
    }

    public static Prosta przesun(Prosta a, Wektor v){
        return new Prosta(a.a, a.b, (a.c + v.dy - a.a * v.dx));
    }

    public static boolean rownolegle(Prosta a, Prosta b){
        return a.a == b.a;
    }

    public static boolean prostopadle(Prosta a, Prosta b){
        return a.a * b.a == -1;
    }

    public static Punkt przeciecie(Prosta a, Prosta b){
        if(geometria.Prosta.prostopadle(a, b)) ; 
        double w = a.a * b.b - b.a * a.b;
        double wx = -a.c * b.b - (-b.c) * a.b;
        double wy = a.a * (-b.c) - b.a * (-a.c);

        return new Punkt(wx/w , wy/w);
    }
    
}
