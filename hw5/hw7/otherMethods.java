
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.applet.*;





public  class otherMethods{
		public static void sort(shape[] shapee){
			int size = shapee.length;
			shape temp ;

			for(int i = 0 ; i < size;i++){
				for(int j = 0 ; j < size ; j++){
					if((shapee[i].area() > shapee[j].area())){
						temp = shapee[i];
						shapee[i] = shapee[j];
						shapee[j] = temp;

					}
				}
			}
		}
		public static shape[] convertAll(shape[] s){
			int size = s.length;
			shape[] temp = new shape[size];
			for(int i = 0 ; i < size;i++){
				temp[i] = new PolyVec(s[i]);
			}
			return temp;
		}
		public static void drawAll(shape[] temp){
			JFrame f = new JFrame("TITLE");
			JPanel p = new JPanel();
			p.setLayout(new BoxLayout(p,BoxLayout.LINE_AXIS));
			for(int i = 0;i<temp.length;i++){
				if(temp[i] instanceof Rectangle){
					Rectangle rec = (Rectangle) temp[i];
					p.add(rec);
				}
				else if(temp[i] instanceof Triangle){
					Triangle tri = (Triangle) temp[i];
					p.add(tri);
				}
				else if(temp[i] instanceof Circle){
					Circle cir = (Circle) temp[i];
					p.add(cir);
				}
				else if(temp[i] instanceof ComposedShape){
					ComposedShape com = (ComposedShape)temp[i];
					p.add(com);
				}
			}
			f.add(p);
			f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			f.setSize(2000,2000);
			f.setVisible(true);
		}
		

	}