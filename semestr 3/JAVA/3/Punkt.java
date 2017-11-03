package geometria;

public class Punkt {
    private double x, y;

    public Punkt(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Punkt() {
        x = 0;
        y = 0;
    }

    @Override
    public String toString(){
        return "("+x +", "+ y +")";
    }

    public void przesun(Wektor v) {
        this.x = this.x + v.dx;
        this.y = this.y + v.dy;
    }

    public void obroc(Punkt p, double kat) { // kat w stopniach
        this.x = (this.x - p.x)*Math.cos(kat*(Math.PI/180))+(this.y - p.y) * Math.sin(kat*(Math.PI/180))+p.x;
        this.y = (this.x - p.x)*Math.sin(kat*(Math.PI/180))-(this.y - p.y) * Math.cos(kat*(Math.PI/180))-p.y;
    }

    public void odbij(Prosta p) {
        double d = ((p.a * p.a * y)-(2*p.a*p.b*x)-(2*p.c*p.b)-(p.b*p.b*y))/(p.a*p.a + p.b*p.b);
        x=(p.a*(d-y))/p.b + x;
        y=d;
    }

    public static boolean wspolliniowe(Punkt a, Punkt b, Punkt c){
        double AC = (b.y - a.y)/(b.x - a.x); 
        double AB =(c.y - a.y)/(c.x - a.x);
        return AC==AB;

    }

    public static boolean rozne(Punkt a, Punkt b){ //equals
        if(a.x == b.x && a.y == b.y) return false;
        else return true;
    }

}