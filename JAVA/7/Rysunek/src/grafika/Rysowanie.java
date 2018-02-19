package grafika;
import java.awt.BorderLayout;
import java.awt.Canvas;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.event.*;
import java.awt.Color;
import java.util.LinkedList;
import java.awt.Point;
import java.awt.List;

/**
 *
 * @author Szymon
 */


public class Rysowanie {
    Frame f = new Frame("Rysowanie kresek");
    private Color currentColor;
    
//trzymanie narysowanych kresek 
    private final LinkedList<Kreska> kreski = new LinkedList<>();

    public void dodaj(int x1, int y1, int x2, int y2){
        dodaj(x1,y1,x2,y2,Color.BLACK);
    }

    public void dodaj(int x1, int y1, int x2, int y2, Color kol){
        kreski.add(new Kreska(new Point(x1,y1),new Point(x2, y2), kol));
    }

    void wyczysc() {
        kreski.clear();
    }

    public void cofnij() {
        if(kreski.isEmpty()){
            throw new NullPointerException("Brak kresek do usuniecia");
        }
        kreski.removeLast();
    }
    
    public void usunPierwsza() {
        if(kreski.isEmpty()){
            throw new NullPointerException("Brak kresek do usuniecia");
        }
        kreski.removeFirst();
  }

  //start
      public void display() {
          f.setBounds(100, 100, 1000, 1000);
          f.addWindowListener(new WindowAdapter() {
               @Override
               public void windowClosing(WindowEvent windowEvent){
                  System.exit(0);
               }        
            }); 
          MouseListener ml = new MouseListener();
          KeyListener kl = new KeyListener();
          Plotno plot = new Plotno();
          f.add(plot, BorderLayout.CENTER);
          plot.addMouseListener(ml);
          plot.addKeyListener(kl);
          
          List colors = new List(1, false);
          colors.add("BLACK");
          colors.add("ORANGE");
          colors.add("CYAN");
          colors.add("BLUE");
          colors.add("DARK GRAY");
          
          f.add(colors, BorderLayout.WEST);
          colors.setBackground(Color.LIGHT_GRAY);
          colors.addItemListener(new ItemListener(){
            @Override
            public void itemStateChanged(ItemEvent e){
                if(null!=colors.getSelectedItem())switch (colors.getSelectedItem()) {
                    case "BLACK":
                        currentColor=Color.BLACK;
                        break;
                    case "ORANGE":
                        currentColor=Color.ORANGE;
                        break;
                    case "CYAN":
                        currentColor=Color.CYAN;
                        break;
                    case "BLUE":
                        currentColor=Color.BLUE;
                        break;
                    case "DARK GRAY":
                        currentColor=Color.DARK_GRAY;
                        break;
                    default:
                        break;
                }
            }});
          
          
          f.setVisible(true);
          
      }

//nasz canvas
      public class Plotno extends Canvas {
          public Plotno(){
              setBackground (Color.PINK);
              setSize(500, 500);
          }
          @Override
          public void paint(Graphics g) {
              super.paint(g);
              for (Kreska line : kreski) {
                  g.setColor(line.kolor);
                  g.drawLine(line.poczatek.x,line.poczatek.y,line.koniec.x, line.koniec.y);
              }
          }
     }
 //zdarzenia myszki
      public class MouseListener extends MouseAdapter {
          int x = 0;
          int y =0;
          int sx = 0;
          int sy = 0;


          @Override
          public void mousePressed(MouseEvent e) {
              x = e.getX();
              y = e.getY();
          }
          

          @Override
          public void mouseReleased(MouseEvent e) {
              sx = e.getX();
              sy = e.getY();
              dodaj(x,y,sx,sy, currentColor);
              Canvas temp = (Canvas)e.getSource();
              Graphics g = temp.getGraphics();
              temp.paint(g);
          }
          
          
      }
//zdarzenia klawiatury
     public class KeyListener extends KeyAdapter {
         
         @Override
         public void keyReleased(KeyEvent e){
             switch (e.getKeyCode()) {
                 case KeyEvent.VK_BACK_SPACE:
                     wyczysc();
                     break;
                 case KeyEvent.VK_B:
                 case KeyEvent.VK_L:
                     cofnij();
                     break;
                 case KeyEvent.VK_F:
                     usunPierwsza();
                     break;
                 default:
                     break;
             }
             
             Canvas temp = (Canvas)e.getSource();
             Graphics g = temp.getGraphics();
             temp.paint(g);
         }        
     }
}
