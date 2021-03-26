

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.applet.*;



interface shape extends Comparable<shape>{
	
	public void set(double a , double b);
	public  double get_x();
	public  double get_y();
	public double area();
	public double perimeter();
	public void post_increment();
	public void pre_increment();
	public void post_decrement();
	public void pre_decrement();

	public int compareTo(shape temp);
	public void draw(Graphics obj);
	public void paintComponent(Graphics obj);
	

}