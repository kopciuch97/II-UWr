package geometria;

public class Odcinek{
    Punkt a,b;

    public Odcinek(Punkt a, Punkt b){
        this.a =a;
        this.b =b;
    }

    @Override
    public String toString(){
        return "Odcinek - " + a.toString() +" - "+ b.toString();
    }

    public void przesun(Wektor v){
        a.przesun(v);
        b.przesun(v);
    }

    public void obroc(Punkt p,double kat){
        a.obroc(p, kat);
        b.obroc(p, kat);
    }

    public void odbij(Prosta p){
        a.odbij(p);
        b.odbij(p);
    }

}