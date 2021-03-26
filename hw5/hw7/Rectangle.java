import java.awt.*;
import java.awt.event.*;
import javax.swing.*;



public class Rectangle extends JPanel implements shape {
	private double  x ;
	private double y;
	private double width;
	private double height;
	private double area , perimeter;
	public Rectangle(){
		this(0,0);
		this.set(0,0);
		

	}
	public Rectangle(double a, double b,double c, double d){
		width = a;
		height = b; 
		x = c;
		y = d;
	}
	public Rectangle(Rectangle other){
		x = other.get_x();
		y = other.get_y();
		width = other.get_width();
		height = other.get_height(); 
	}
	public void  set_rec(double a, double b,double c, double d){
		width = a;
		height = b; 
		x = c;
		y = d;
	}
	public Rectangle(double a, double b){
		width = a;
		height = b; 
	}
	public void set(double a ,double b){
		x = a;
		y = b;
	}
	public  double get_x(){
		return x;
	}
	public  double  get_y(){
		return y;
	}
	public double get_width(){return width;}
	public double get_height(){return height;}
	public double area(){

		return width*height;}
	public double perimeter(){return 2*width +2*height;}
	public void post_increment(){
		this.set(y++,y++);
		
	}
	public void pre_increment(){
		this.set(++x,++y);
		
		
	}
	public void pre_decrement(){
		this.set(--x,--y);
		
	}
	public void post_decrement(){
		this.set(x--,x--);
				
	}

	public int compareTo(shape temp){
	 	return Double.valueOf(this.area()).compareTo(Double.valueOf(temp.area()));
	 }

	 public void draw(Graphics obj){
	 	int width = (int)get_width();
	 	int height = (int)get_height();
	 	int x = (int)get_x();
	 	int y = (int)get_y();
	 	obj.setColor(Color.white);
	 	obj.drawRect(x,y,width,height);
	 	obj.setColor(Color.RED);
	 	obj.fillRect(x,y,width,height);
	 }
	 public void paintComponent(Graphics obj){
	 	super.paintComponent(obj);
	 	draw(obj);
	 }
	 public String toString(){
		return String.format("%f,%f,%f,%f",width,height,x,y);
	}

}