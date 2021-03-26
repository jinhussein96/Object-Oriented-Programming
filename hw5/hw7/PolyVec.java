
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.ArrayList;
import java.lang.Math; 



public class PolyVec extends Polygon{
	private ArrayList<point2D> points = new ArrayList<point2D>();
	public PolyVec(){super();}
	public PolyVec(ArrayList<point2D> point){points = point;}
	public PolyVec(shape obj){
		if(obj instanceof Rectangle){
			Rectangle rec = (Rectangle)obj;
			point2D point = new point2D(rec.get_x(),rec.get_y());
		points.add(point);
		point = new point2D(rec.get_x()+rec.get_width(),rec.get_y());
		points.add(point);
		point = new point2D(rec.get_x()+rec.get_width(),rec.get_y()+rec.get_height());
		points.add(point);
		point = new point2D(rec.get_x(),rec.get_y()+rec.get_height());
		points.add(point);
		size = 4;
		area = rec.area();
			
		}
		else if(obj instanceof Circle){
			Circle cir = (Circle)obj;
			area = cir.area();
		perimeter = cir.perimeter();
		size = 200;
		double i = 3.6;
		int j = 0;

		point2D point = new point2D();
		while(i <= 360){
		
			double a = cir.get_radius()*(Math.cos(Math.toRadians(i)))+cir.get_x();
			double b = cir.get_radius()*(Math.sin(Math.toRadians(i)))+cir.get_y();
			point = new point2D(a,b);
			i +=3.6*j*(3.14/180);
			j++;
			
			points.add(point);
			
	
		}

		}
		else if(obj instanceof Triangle){
			Triangle tri = (Triangle)obj;
				size = 3;
			area = tri.area();
			perimeter = tri.perimeter();
			point2D point = new point2D(tri.get_x(),tri.get_y());
			points.add(point);
			point2D point2 = new point2D(tri.get_x2(),tri.get_y2());
			points.add(point2);

			point2D point3 = new point2D(tri.get_x3(),tri.get_y3());
			points.add(point3);
		}

	}
	public PolyVec(Rectangle rec){
		point2D point = new point2D(rec.get_x(),rec.get_y());
		points.add(point);
		point = new point2D(rec.get_x()+rec.get_width(),rec.get_y());
		points.add(point);
		point = new point2D(rec.get_x()+rec.get_width(),rec.get_y()+rec.get_height());
		points.add(point);
		point = new point2D(rec.get_x(),rec.get_y()+rec.get_height());
		points.add(point);
		size = 4;
		area = rec.area();

	}
	public PolyVec(Circle cir){
		area = cir.area();
		perimeter = cir.perimeter();
		size = 200;
		double i = 3.6;
		int j = 0;

	point2D point = new point2D();
	while(i <= 360){
		
		double a = cir.get_radius()*(Math.cos(Math.toRadians(i)))+cir.get_x();
		double b = cir.get_radius()*(Math.sin(Math.toRadians(i)))+cir.get_y();
		point = new point2D(a,b);
		i +=3.6*j*(3.14/180);
		j++;
		
		points.add(point);
		
	
	}
	}
	public PolyVec(Triangle tri){
		size = 3;
		area = tri.area();
		perimeter = tri.perimeter();
		point2D point = new point2D(tri.get_x(),tri.get_y());
		points.add(point);
		point2D point2 = new point2D(tri.get_x2(),tri.get_y2());
		points.add(point2);

		point2D point3 = new point2D(tri.get_x3(),tri.get_y3());
		points.add(point3);
	}
	public ArrayList<point2D> get_array(){return points;}
	public void draw(Graphics obj){
		int[] x = new int[size];
		int[] y = new int[size];
		int i =0;
		for(point2D p : points){
			x[i] = (int)p.get_x();
			y[i] = (int)p.get_y();
			i++;
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
	public void post_increment(){
		for(point2D p : points){
			p.post_increment();
		}
	}
	public void pre_increment(){
		for(point2D p : points){
			p.pre_increment();
		}
	}
	public void post_decrement(){
		for(point2D p : points){
			p.post_decrement();
		}
	}
	public void pre_decrement(){
		for(point2D p : points){
			p.pre_decrement();
		}
	}
	public int compareTo(shape temp){return 0;}
}