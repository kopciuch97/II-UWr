package geometria;


public final class Wektor{

public final double  dx, dy;

@Override
public String toString(){
    return "["+dx +", "+dy+"]";
}

public Wektor(double dx,double dy){
    this.dx = dx;
    this.dy = dy;
}

public static Wektor sumuj(Wektor a, Wektor b){
    return new Wektor(a.dx + b.dx, a.dy+b.dy);
} 
    
}