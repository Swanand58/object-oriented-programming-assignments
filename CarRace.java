
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

 public class CarRace extends Frame implements KeyListener
{

int car1x, car2x,car1y,car2y,tyre1x1,tyre1x2,tyre1y,tyre2x1,tyre2x2,tyre2y;
Label l;
CarRace()
{
    setLayout(new FlowLayout(FlowLayout.LEFT));
    l=new Label();
    l.setBounds(10,20,500,200);
    add(l);
    
   setBounds(0,0,800,500);
   setVisible(true);

   addKeyListener(this);
  
   addWindowListener(new WindowAdapter(){
       
       public void windowClosing(WindowEvent e)
       {
           System.exit(0);
       }
   });
  
   car1x=5; car1y=330; tyre1y=340; tyre1x1=10;  tyre1x2= 60;  
   car2x=5; car2y=225; tyre2y=235; tyre2x1=10;  tyre2x2= 60; 
 }
  
 public void paint(Graphics g)
{ 
    
    g.setColor(Color.green);    
    g.fillRect(0,250,800,10);

    g.setColor(Color.green);    
    g.fillRect(0,355,800, 10);
    
    g.setColor(Color.black);    
    g.fillRect(getWidth()-50,10,20, getHeight()-20);
    
    
    if(car1x+80 == getWidth()-50 )
    {
        l.setText("CAR-1 WON");
        System.out.println("CAR 1 won");
        
         car1x=5; car1y=330; tyre1y=340; tyre1x1=10;  tyre1x2= 60;  
         car2x=5; car2y=225; tyre2y=235; tyre2x1=10;  tyre2x2= 60;
    }
    else if(car2x+80 == getWidth()-50 )
    {
        l.setText("CAR-2 WON");
        System.out.println("CAR 2 won");

         car1x=5; car1y=330; tyre1y=340; tyre1x1=10;  tyre1x2= 60;  
         car2x=5; car2y=225; tyre2y=235; tyre2x1=10;  tyre2x2= 60;
    }
    
    ////CAR 1
    g.setColor(Color.red);            // for car body
    g.fillRoundRect(car1x,car1y,80, 20,5,5);
    g.fillRoundRect(car1x+12,car1y-15,50,20,10,10);
    
    g.setColor(Color.black);     //  for car tyres
    g.fillOval(tyre1x1,tyre1y,20, 20);
    g.fillOval(tyre1x2,tyre1y,20, 20);
    
        ////CAR 2
    g.setColor(Color.orange);            // for car body
    g.fillRoundRect(car2x,car2y,80, 20,5,5);
    g.fillRoundRect(car2x+12,car2y-15,50,20,10,10);
    
    g.setColor(Color.black);     //  for car tyres
    g.fillOval(tyre2x1,tyre2y,20, 20);
    g.fillOval(tyre2x2,tyre2y,20, 20);

 }
 
  public void keyTyped(KeyEvent e)
  {
  
  switch(e.getKeyChar())
  {
      case 'd':
       car2x+=5;  tyre2x1+=5;  tyre2x2+=5;
       repaint();
       break;
      case 'a':
        car2x-=5;  tyre2x1-=5;  tyre2x2-=5;
        repaint();
        break;  
  }
      
  }

  public void keyPressed(KeyEvent e)
  {
      int id= e.getKeyCode();
      switch(id)
      {
          case KeyEvent.VK_RIGHT:
	       car1x+=5;  tyre1x1+=5;  tyre1x2+=5;
                repaint();
                break;
          case KeyEvent.VK_LEFT:
	       car1x-=5;  tyre1x1-=5;  tyre1x2-=5;
                repaint();
                break;
      } 
  }
  
 public void keyReleased(KeyEvent e){}

 public static void main(String x[])
 {
   new CarRace();

 }

}