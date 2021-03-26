import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.ArrayList;
import java.lang.Math; 



public class PolyDyn extends Polygon{
	private point2D[] points;
    public PolyDyn(){}
	public PolyDyn(Circle cir){
		size = 200;
		points = new point2D[size];
		area = cir.area();
		perimeter = cir.perimeter();
		double i = 3.6;
		int j = 0;

	 points = new point2D[size];
	 point2D point ;
	while(i <= 360){
		i +=3.6*j*(3.14/180);
		double a = cir.get_radius()*(Math.cos(Math.toRadians(i)))+cir.get_x();
		double b = cir.get_radius()*(Math.sin(Math.toRadians(i)))+cir.get_y();
		
		point = new point2D(a,b);
		
		points[j]=point;
		j++;}
		

	}
	public PolyDyn(Rectangle rec){
		area = rec.area();
		perimeter = rec.perimeter();
		size = 4;
		points = new point2D[size];
		point2D point = new point2D(rec.get_x(),rec.get_y());
		points[0] = point;
		point = new point2D(rec.get_x()+rec.get_width(),rec.get_y());
		points[1] = point;
		point = new point2D(rec.get_x()+rec.get_width(),rec.get_y()+rec.get_height());
		points[2] = point;
		point = new point2D(rec.get_x(),rec.get_y()+rec.get_height());
		points[3] = point;
		

	}
	public PolyDyn(Triangle tri){
		size = 3;
		area = tri.area();
		perimeter = tri.perimeter();
		points = new point2D[size];
		point2D point = new point2D(tri.get_x(),tri.get_y());
		points[0] = point;
		point2D point2 = new point2D(tri.get_x2(),tri.get_y2());
		points[1] = point2;

		point2D point3 = new point2D(tri.get_x3(),tri.get_y3());
		points[2] = point3;
	}
	public void draw(Graphics obj){
		int x[] = new int[size];
		int y[] = new int[size];
		for(int i = 0 ; i < size; i++){
			x[i] = (int)points[i].get_x();
			y[i] = (int)points[i].get_y();
		}
		obj.setColor(Color.red);
	 	obj.drawPolygon(x,y,size);
	 	obj.setColor(Color.pink);
	 	obj.fillPolygon(x,y,size);
	}
	public void paintComponent(Graphics obj){
		super.paintComponent(obj);
	 	draw(obj);
	}
	public void set(double a , double b){}
	public  double get_x(){return 0;}
	public  double get_y(){return 0;}
	public double area(){return area;}
	public double perimeter(){return perimeter;}
	public int compareTo(shape temp){return 0;}

	public void post_increment(){
		for(int i = 0 ; i < size ; i++){
			points[i].post_increment();
		}

	}
	public void pre_increment(){
		for(int i = 0 ; i < size ; i++){
			points[i].pre_increment();
		}
	}
	public void post_decrement(){
		for(int i = 0 ; i < size ; i++){
			points[i].post_decrement();
		}
	}
	public void pre_decrement(){
		for(int i = 0 ; i < size ; i++){
			points[i].pre_decrement();
		}

	}

}