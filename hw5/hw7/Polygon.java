import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


abstract class Polygon extends JPanel implements shape{
	protected int size;
	protected double area , perimeter;
		
	public class point2D{
		private double x , y;
		private int size;
		
		public point2D(){
			this(0,0);
		}
		public point2D(double x , double y){
			this.x = x;
			this.y = y;
		}
		public void set(double x,double y)
		{
			this.x = x;
			this.y = y;	
		}
		public double get_x(){return x;}
		public double get_y(){return y;}
		public void post_increment(){x++;y++;}
		public void pre_increment(){++x;++y;};
		public void post_decrement(){x--;y--;}
		public void pre_decrement(){--x;--y;}
	}
	public Polygon(){}
	public void draw(Graphics obj){}
	public void paintComponent(Graphics obj){}
	

}