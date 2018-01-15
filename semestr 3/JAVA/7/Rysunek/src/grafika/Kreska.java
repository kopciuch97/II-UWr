package grafika;
import java.awt.Point;
import java.awt.Color;

/**
 *
 * @author Szymon
 */
public class Kreska {
    protected Point poczatek, koniec;
    public final Color kolor;
    
    public Kreska (Point pocz, Point kon, Color kol) {
        this.poczatek=pocz;
        this.koniec=kon;
        this.kolor=kol;
    }
    
    
}
