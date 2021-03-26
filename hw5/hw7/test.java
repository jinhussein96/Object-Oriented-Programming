
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.applet.*;


public class test{
	
	public static  void main(String[] args){
		Rectangle rec = new Rectangle(200,200,5,5);
		Rectangle rec1 = new Rectangle(40,30,200,200);
		Circle cir = new Circle(250,100,100);
		Circle cir1 = new Circle(100,100,100);
		Triangle t = new Triangle(200,200,150,150,300,250,300);
		Triangle t1 = new Triangle(50,200,275,175,150,225,150);
		ComposedShape com = new ComposedShape(cir,cir1);

		shape[] s = new shape[3];
		s[0] = rec;
		s[1] = com;
		s[2] = cir;

		PolyVec v = new PolyVec(t);
		PolyDyn c = new PolyDyn(t);
		JFrame f = new JFrame("Title");
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.add(com);
		f.setSize(250,200);
		f.setVisible(true);
		//otherMethods.drawAll(s);
		
		
	}
}