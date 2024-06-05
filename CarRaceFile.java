import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.nio.ByteBuffer;

public class CarRaceFile extends Frame implements KeyListener{


	int car1x, car2x,car1y,car2y,tyre1x1,tyre1x2,tyre1y,tyre2x1,tyre2x2,tyre2y;
	Label l;
	
	CarRaceFile ()
	{
	    setLayout(new FlowLayout(FlowLayout.LEFT));
	    l=new Label();
	    l.setBounds(10,20,500,200);
	    add(l);
	    
	   setBounds(0,0,800,500);
	   setVisible(true);

	   addKeyListener(this);
	  // setFocusable(true);
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
	        // Set to initial positions
	         car1x=5; car1y=330; tyre1y=340; tyre1x1=10;  tyre1x2= 60;  
	         car2x=5; car2y=225; tyre2y=235; tyre2x1=10;  tyre2x2= 60;
	         
	         BufferedWriter out = null;
	         try {
				BufferedReader br = new BufferedReader(new FileReader("C:/Users/Swanand Khonde/vsc/psuo/CarResults2.txt"));
				String currentScore = "0";
				int currentScoreNumber = 0;
				
				while ((currentScore = br.readLine()) != null) {
		            currentScoreNumber=(Integer.parseInt(currentScore==null?"0":currentScore));
		        }
				
				
				System.out.println("Car1 Wins\nCar 1 Current Score: "+currentScoreNumber);
				
				br.close();
				
				out = new BufferedWriter(new FileWriter("C:/Users/Swanand Khonde/vsc/psuo/CarResults2.txt", false));
				out.write(String.valueOf(currentScoreNumber+1));
				
				
				out.close();
				
			} catch (IOException e) {
				
				e.printStackTrace();
			}
	    }
	
	    else if(car2x+80 == getWidth()-50 )
	    {
	        l.setText("CAR-2 WON");
	        // Set to initial positions
	         car1x=5; car1y=330; tyre1y=340; tyre1x1=10;  tyre1x2= 60;  
	         car2x=5; car2y=225; tyre2y=235; tyre2x1=10;  tyre2x2= 60;
	         
	         BufferedWriter out = null;
	         try {
				BufferedReader br = new BufferedReader(new FileReader("C:/Users/Swanand Khonde/vsc/psuo/CarResults2.txt"));
				String currentScore = "0";
				int currentScoreNumber = 0;
				
				while ((currentScore = br.readLine()) != null) {
		            currentScoreNumber=(Integer.parseInt(currentScore==null?"0":currentScore));
		        }
				
				
				System.out.println("Car 2 Wins\nCar 2 Current Score: "+currentScoreNumber);
				
				br.close();
				
				out = new BufferedWriter(new FileWriter("C:/Users/Swanand Khonde/vsc/psuo/CarResults2.txt", false));
				out.write(String.valueOf(currentScoreNumber+1));
				
				
				
				out.close();
				
			} catch (IOException e) {
				
				e.printStackTrace();
			}
	    }
	    
	    ////CAR 1
	    g.setColor(Color.red);            
	    g.fillRoundRect(car1x,car1y,80, 20,5,5);
	    g.fillRoundRect(car1x+12,car1y-15,50,20,10,10);
	    
	    g.setColor(Color.black);     
	    g.fillOval(tyre1x1,tyre1y,20, 20);
	    g.fillOval(tyre1x2,tyre1y,20, 20);
	    
	        ////CAR 2
	    g.setColor(Color.orange);           
	    g.fillRoundRect(car2x,car2y,80, 20,5,5);
	    g.fillRoundRect(car2x+12,car2y-15,50,20,10,10);
	    
	    g.setColor(Color.black);    
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
	
	public static void main(String[] args) {
	
		new CarRaceFile();
	}

}
