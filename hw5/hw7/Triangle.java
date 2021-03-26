import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.lang.Math; 

public class Triangle extends JPanel implements shape{
	private double x1 , y1, x2,y2,x3,y3;
	private double length;

    public Triangle(){}
    public Triangle(double a,double b,double c,double d,double e,double f,double g){
    	length = a;
    	x1 =b;
		y1=c;
		x2=d;
		y2=e;
		x3=f;
		y3=g;

    }


	public void set(double a , double b){
		x1 = a;
		y1 = b;
	}
	public  double get_x(){return x1;}
	public  double get_y(){return y1;}
	public  double get_x2(){return x2;}
	public  double get_y2(){return y2;}
	public  double get_x3(){return x3;}
	public  double get_y3(){return y3;}
	
	public double area(){return (Math.sqrt(3)/4)*Math.pow(length,2);}
	public double perimeter(){ return 3*length;}
	public void post_increment(){
			x1++;
			y1++;
			x2++;
			y2++;
			x3++;
			y3++;
			
	}
	public void pre_increment(){
		++x1;
		++y1;
		++x2;
		++y2;
		++x3;
		++y3;

	}
	public void post_decrement(){
		x1--;y1--;x2--;y2--;x3--;y3--;
			
	}
	public void pre_decrement(){
		--x1;
		--y1;
		--x2;
		--y2;
		--x3;
		--y3;
	}
	public int compareTo(shape temp){
		return Double.valueOf(this.area()).compareTo(Double.valueOf(temp.area()));
	}
	public void draw(Graphics obj){
		int[] x = new int[3];
		int[] y = new int[3];
		x[0] = (int)x1;
		x[1] = (int)x2;
		x[2] = (int)x3;
		y[0] = (int)y1;
		y[1] = (int)y2;
		y[2] = (int)y3;
		obj.setColor(Color.red);
	 	obj.drawPolygon(x,y,3);
	 	obj.setColor(Color.pink);
	 	obj.fillPolygon(x,y,3);


	}
	public void paintComponent(Graphics obj){
		super.paintComponent(obj);
	 	draw(obj);
	}
	public double get_length(){return length;}
}