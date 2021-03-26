import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.ArrayList;


public class ComposedShape extends JPanel implements shape{
	private ArrayList<shape> shapes = new ArrayList<shape>();
	private int main_shape,small_shape;
	Rectangle reca , recb ;
	Triangle tri_a , tri_b;
	Circle cir_a,cir_b;
	public ComposedShape(){};
	public ComposedShape(Rectangle container_rec,Rectangle inner_rec){

		 reca = new Rectangle(container_rec.get_width(),container_rec.get_height(),container_rec.get_x(),container_rec.get_y());
		 recb = new Rectangle(inner_rec.get_width(),inner_rec.get_height(),inner_rec.get_x(),inner_rec.get_y());
		shapes.add(reca);
		shapes.add(recb);
		this.optimalFit(1,1);
			
	}
    public ComposedShape(Rectangle container_rec , Circle inner_cir){
    	reca = new Rectangle(container_rec.get_width(),container_rec.get_height(),container_rec.get_x(),container_rec.get_y());
		cir_b = new Circle(inner_cir.get_radius(),inner_cir.get_x(),inner_cir.get_y()); 
    	shapes.add(reca);
		shapes.add(cir_b);
		this.optimalFit(1,3);
    }
    public ComposedShape(Rectangle container_rec, Triangle inner_tri){
    	reca = new Rectangle(container_rec.get_width(),container_rec.get_height(),container_rec.get_x(),container_rec.get_y());
		tri_b = new Triangle(inner_tri.get_length(),inner_tri.get_x(),inner_tri.get_y(),inner_tri.get_x2(),inner_tri.get_y2(),inner_tri.get_x3(),inner_tri.get_y3());
		shapes.add(reca);
		shapes.add(tri_b);
		this.optimalFit(1,2);
    }
    public ComposedShape(Circle container_cir , Rectangle inner_rec){
    	cir_a = new Circle(container_cir.get_radius(),container_cir.get_x(),container_cir.get_y());
    	recb = new Rectangle(inner_rec.get_width(),inner_rec.get_height(),inner_rec.get_x(),inner_rec.get_y());
    	shapes.add(cir_a);
		shapes.add(recb);
		this.optimalFit(3,1);
    }
    public ComposedShape(Circle container_cir , Triangle inner_tri){
    	cir_a = new Circle(container_cir.get_radius(),container_cir.get_x(),container_cir.get_y());
    	tri_b = new Triangle(inner_tri.get_length(),inner_tri.get_x(),inner_tri.get_y(),inner_tri.get_x2(),inner_tri.get_y2(),inner_tri.get_x3(),inner_tri.get_y3());
		shapes.add(cir_a);
		shapes.add(tri_b);
		this.optimalFit(3,2);
    }
    public ComposedShape(Circle container_cir,Circle inner_cir){
    	cir_a = new Circle(container_cir.get_radius(),container_cir.get_x(),container_cir.get_y());
    	cir_b = new Circle(inner_cir.get_radius(),inner_cir.get_x(),inner_cir.get_y()); 
    	shapes.add(cir_a);
		shapes.add(cir_b);
		this.optimalFit(3,3);
    }
    public ComposedShape(Triangle container_tri , Triangle inner_tri){
    	tri_a = new Triangle(container_tri.get_length(),container_tri.get_x(),container_tri.get_y(),container_tri.get_x2(),container_tri.get_y2(),container_tri.get_x3(),container_tri.get_y3());
		tri_b = new Triangle(inner_tri.get_length(),inner_tri.get_x(),inner_tri.get_y(),inner_tri.get_x2(),inner_tri.get_y2(),inner_tri.get_x3(),inner_tri.get_y3());
		shapes.add(tri_a);
		shapes.add(tri_b);
		this.optimalFit(2,2);
    }
    public ComposedShape(Triangle container_tri,Rectangle inner_rec){
    	tri_a = new Triangle(container_tri.get_length(),container_tri.get_x(),container_tri.get_y(),container_tri.get_x2(),container_tri.get_y2(),container_tri.get_x3(),container_tri.get_y3());
		recb = new Rectangle(inner_rec.get_width(),inner_rec.get_height(),inner_rec.get_x(),inner_rec.get_y());
    	shapes.add(tri_a);
		shapes.add(recb);
		this.optimalFit(2,1);
    }
    public ComposedShape(Triangle container_tri , Circle inner_cir){
    	tri_a = new Triangle(container_tri.get_length(),container_tri.get_x(),container_tri.get_y(),container_tri.get_x2(),container_tri.get_y2(),container_tri.get_x3(),container_tri.get_y3());
		cir_b = new Circle(inner_cir.get_radius(),inner_cir.get_x(),inner_cir.get_y()); 
    	shapes.add(tri_a);
		shapes.add(cir_b);
		this.optimalFit(2,3);
    }
    
	public void set(double a , double b){}
	public  double get_x(){return 0;}
	public  double get_y(){return 0;}
	public double area(){return 0;}
	public double perimeter(){return 0;}
	public void post_increment(){}
	public void pre_increment(){}
	public void post_decrement(){}
	public void pre_decrement(){}
	public int compareTo(shape temp){return 0;}
	public void draw(Graphics obj){
		for(shape s:shapes){
			
			s.draw(obj);
		}
	}
	public void paintComponent(Graphics obj){
		super.paintComponent(obj);
	 	draw(obj);
	}
	public void optimalFit(int main_shape,int small_shape){
		if(main_shape == 1 && small_shape == 1){
        
             Rectangle rec_c = new Rectangle();
            double temp1 , temp2;
            temp1 = recb.get_height();
            temp2 = recb.get_width();
            while(temp1 < reca.get_height()){

               while(temp2 < reca.get_width()){
					
	               	rec_c= new Rectangle(recb.get_width(),recb.get_height(),temp2,temp1);
	               	shapes.add(rec_c);

                    temp2 += recb.get_width();
                }
            temp2 = recb.get_width();
            temp1 +=recb.get_height();

            }

     
   		}
   		 else if(main_shape ==1 && small_shape == 2){
        
        double point_x=0;
    
        double  point_y = (Math.pow(tri_b.get_length(),2)) - (Math.pow((tri_b.get_length()/2),2));
        point_y = Math.sqrt(point_y);
        double y = point_y;
        double point3_x = (tri_b.get_length())/2;
        double point3_y=0;
        double triangle_counter = 0;
        Triangle tri = new Triangle();
        while(point_y <= reca.get_height()){
            while(point_x <= reca.get_width() - tri_b.get_length()/2){
            	tri = new Triangle(tri_b.get_length(),point_x,point_y,point_x+tri_b.get_length(),point_y,point3_x,point3_y );
              	shapes.add(tri);
                if(point3_x+tri_b.get_length() < reca.get_width()){
                	tri = new Triangle(tri_b.get_length(),point_x,point_y,point_x+tri_b.get_length(),point_y,point3_x,point3_y);
              		shapes.add(tri);
                    
                }
                point_x += tri_b.get_length();
                point3_x += tri_b.get_length();
            
        
            }
            point_x = 0;
            point3_x = tri_b.get_length()/2;
            point3_y += y;
            point_y += y;
        }
    }
   		else if(main_shape == 1 && small_shape == 3){
        

       double temp_height = cir_b.get_radius();
        double temp_width = cir_b.get_radius();
        Circle cir;
            while(temp_height <= reca.get_height()-cir_b.get_radius()){
                while(temp_width <=reca.get_width()-cir_b.get_radius()){
                	
                	cir = new Circle(cir_b.get_radius(),temp_width,temp_height);
    		       shapes.add(cir);
        
                    temp_width += 2*cir_b.get_radius();
                }

            temp_width =cir_b.get_radius();
            temp_height += 2*cir_b.get_radius();
            }
    }
    else if(main_shape == 3 && small_shape == 1){
        
        double point1_x=cir_a.get_radius() - recb.get_width()/2;
        double point1_y=cir_a.get_y()-recb.get_height() /2;;
        double point2_x=cir_a.get_radius()-recb.get_width()/2;
        double point2_y=cir_a.get_radius()-recb.get_height()/2;
        double temp = (2*cir_a.get_radius()) / recb.get_width();
        double temp2 = 0;
        double circle_counter =0;
        Rectangle rec;

            	
        while(point1_y >= 0 && point2_y <= 2*cir_a.get_radius()){
            while(point1_x >= 0 && point2_x <= 2*cir_a.get_radius() &&temp2 < temp){

            	rec = new Rectangle(recb.get_width(),recb.get_height(),point1_x,point1_y);
               	shapes.add(rec);
                rec = new Rectangle(recb.get_width(),recb.get_height(),point2_x,point2_y);
               	shapes.add(rec);


               	rec = new Rectangle(recb.get_width(),recb.get_height(),point1_x,point2_y);
               	shapes.add(rec);
                
                rec = new Rectangle(recb.get_width(),recb.get_height(),point2_x,point1_y);
                shapes.add(rec);
                
                
                temp2++;
                point1_x -= recb.get_width();
                point2_x += recb.get_width();    
            }
            
            temp -= 2;
            temp2 = 0;

            point1_x=cir_a.get_radius()-recb.get_width()/2;
            point2_x=cir_a.get_radius()-recb.get_width()/2;
            point1_y -= recb.get_height();
            point2_y += recb.get_height();

                        
        } 
    }
    else if(main_shape == 2 && small_shape ==1){
    
        double triangle_height =(Math.pow(tri_a.get_length(),2))-( Math.pow(tri_a.get_length()/2,2));
        triangle_height=Math.sqrt(triangle_height);
        double point1_x = (1/Math.sqrt(3))*(recb.get_height());
        double temp_point_x=point1_x;
        double point1_y = triangle_height-recb.get_height();
        double counter = tri_a.get_length() / recb.get_height();
        int counter2 = 0;
        int counter3 =1;
        double temp_triangle_length =tri_a.get_length();
        Rectangle rec = new Rectangle();
        while(point1_y >= 0.0){
        while(point1_x+recb.get_width() < temp_triangle_length-(2*temp_point_x)){

            rec = new Rectangle(recb.get_width(),recb.get_height(),point1_x,point1_y);    
           	shapes.add(rec);
        
            point1_x += recb.get_width();
            counter2++;
    
        }
		    counter3++;
		    point1_x = (1/Math.sqrt(3))*recb.get_height();
		    point1_x *=counter3;
		    
		    point1_y -= recb.get_height();
		    temp_triangle_length -= recb.get_height()/2;
		    counter = temp_triangle_length/recb.get_width();
		}

    }
    else if(main_shape == 3 && small_shape == 3){
         
       double temp_num1 = cir_a.get_radius();
        double temp_num2 = cir_a.get_radius();
        double temp_num3 = cir_a.get_radius();
        double temp_num4 = cir_a.get_radius();
        double counter2 =0;
        double counter3 =0;
        double counter = 2*cir_a.get_radius() / (cir_b.get_radius() * 2);
        Circle cir;
        while (temp_num3 > cir_b.get_radius()){

            while(temp_num1 >  cir_b.get_radius()&& counter2 < counter ){
                counter3++;
                cir = new Circle(cir_b.get_radius(),temp_num1,temp_num3);
                shapes.add(cir);
                
                cir = new Circle(cir_b.get_radius(),temp_num2,temp_num3);
                shapes.add(cir);
                temp_num1 -= 2*cir_b.get_radius();
                temp_num2 += 2*cir_b.get_radius();
                counter2++;
            }
            counter -= 2;
            counter2 = 0;
            temp_num1 = cir_a.get_radius();
            temp_num2 = cir_a.get_radius();
            temp_num3 -= 2*cir_b.get_radius();
        }
  
        temp_num1 = cir_a.get_radius();
        temp_num2 = cir_a.get_radius();
        temp_num3 = cir_a.get_radius();
        temp_num4 = cir_a.get_radius();
        counter =2* cir_a.get_radius() / (cir_b.get_radius() * 2);
        counter2=0;
        while (temp_num3 < 2*cir_a.get_radius() - cir_b.get_radius()){

            while(temp_num1 > cir_b.get_radius() && counter2 < counter ){
                counter3++;
                cir = new Circle(cir_b.get_radius(),temp_num1,temp_num3);
                shapes.add(cir);
                cir = new Circle(cir_b.get_radius(),temp_num2,temp_num3);
                shapes.add(cir);
                temp_num1 -= 2*cir_b.get_radius();
                temp_num2 += 2*cir_b.get_radius();
                counter2++;
                
            }
        counter -= 2;
        counter2 = 0;
        temp_num1 = cir_a.get_radius();
        temp_num2 = cir_a.get_radius();
        temp_num3 += 2*cir_b.get_radius();

        }
    }

   		
	}


}