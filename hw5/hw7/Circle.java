import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class Circle extends JPanel implements shape{
	private double  x ;
	private double y;
	private double radius ;
	public Circle(){
		this(0,0,0);
	}
	public Circle(double r , double a , double b){
		radius = r;
		x = a;
		y = b;
	}

	public void set(double a , double b){
		x = a;
		y = b;
	}
	public  double get_x(){
		return x;
	}
	public double get_radius(){return radius;}
	public  double get_y(){return y;}
	public double area(){return 3.14*radius*radius;}
	public double perimeter(){return 2*3.14*radius;}
	public void pre_increment(){
		this.set(++x,++y);
		
	}
	public void post_increment(){
		this.set(x++,y++);
	}
	public void pre_decrement(){
		this.set(--x,--y);
		
	}
	public void post_decrement(){
		this.set(x--,y--);
		
	}
	public int compareTo(shape temp){
		return Double.valueOf(this.area()).compareTo(Double.valueOf(temp.area()));
	}
	public void draw(Graphics obj){
		int width = (int)get_radius();
	 	int height = (int)get_radius();
	 	int x = (int)get_x();
	 	int y = (int)get_y();
	 	obj.setColor(Color.white);
	 	obj.drawOval(x,y,width,height);
	 	obj.setColor(Color.green);
	 	obj.fillOval(x,y,width,height);	
	}
	public void paintComponent(Graphics obj){
		super.paintComponent(obj);
	 	draw(obj);
	}

}