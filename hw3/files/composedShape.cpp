
#include "composedShape.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "shape.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;


composedShape::composedShape(rectangle& container_rec,rectangle& inner_rec){
	//shape* rec = new rectangle(container_rec->get_width(),container_rec->get_height(),container_rec->get_x(),container_rec->get_y());
 	//shape* rec1 = new rectangle(inner_rec->get_width(),inner_rec->get_height(),inner_rec->get_x(),inner_rec->get_y());	
	reca = container_rec;
    recb = inner_rec;
    vec.push_back(&reca);
    vec.push_back(&recb);
    optimalFit(1,1);
 }
 composedShape::composedShape(rectangle& container_rec , circle& inner_cir){
 	//shape* rec = new rectangle(container_rec->get_width(),container_rec->get_height(),container_rec->get_x(),container_rec->get_y());
 	//shape* cir = new circle(inner_cir->get_radius(),inner_cir->get_x(),inner_cir->get_y());
 	reca = container_rec;
    cir_b = inner_cir;
    vec.push_back(&reca);
    vec.push_back(&cir_b);
    optimalFit(1,3);  
 }
composedShape::composedShape(rectangle& container_rec, triangle& inner_tri){
	/*shape* rec = new rectangle(container_rec->get_width(),container_rec->get_height(),
							   container_rec->get_x(),container_rec->get_y());
 	
 	shape* tri = new triangle(inner_tri->get_lengthgth(),
							   inner_tri->get_x(),inner_tri->get_y(),
							   inner_tri->get_x2(),inner_tri->get_y2(),
							   inner_tri->get_x3(),inner_tri->get_y3());*/
 	reca = container_rec;
 	tri_b = inner_tri;
 	vec.push_back(&reca);
 	vec.push_back(&tri_b);
 	optimalFit(1,2);
}
composedShape::composedShape(circle& container_cir , rectangle& inner_rec){
	cir_a=container_cir;
	recb = inner_rec;
	vec.push_back(&cir_a);
	vec.push_back(&recb);
	optimalFit(3,1);
}
composedShape::composedShape(circle& container_cir , triangle& inner_tri){
	cir_a=container_cir;
	tri_b = inner_tri;
	vec.push_back(&cir_a);
	vec.push_back(&tri_b);
	optimalFit(3,2);
}
composedShape::composedShape(circle& container_cir,circle& inner_cir){
	cir_a=container_cir;
	vec.push_back(&cir_a);
	cir_b = inner_cir;
	vec.push_back(&cir_b);
	optimalFit(3,3);
}
composedShape::composedShape(triangle& container_tri , triangle& inner_tri){
	tri_a = container_tri;
	tri_b = inner_tri;
	vec.push_back(&tri_a);
	vec.push_back(&tri_b);
	optimalFit(2,2);
}
composedShape::composedShape(triangle& container_tri,rectangle& inner_rec){
	tri_a = container_tri;
	recb = inner_rec;
	vec.push_back(&tri_a);
	vec.push_back(&inner_rec);
	optimalFit(2,1);
}
composedShape::composedShape(triangle& container_tri , circle& inner_cir){
	tri_a = container_tri;
	cir_b = inner_cir;
	vec.push_back(&tri_a);
	vec.push_back(&cir_b);
	optimalFit(2,3);
	
	
}

void composedShape::optimalFit(int main_shape,int small_shape){ 

    if(main_shape ==1 && small_shape == 1){
        
             rectangle rec_c;
            double temp1 , temp2;
            temp1 = recb.get_height();
            temp2 = recb.get_width();
            while(temp1 < reca.get_height()){

               while(temp2 < reca.get_width()){
	               	shape *newShape = new rectangle(recb.get_width(),recb.get_height(),temp2,temp1);
	               	rectangle *rec = dynamic_cast<rectangle*>(newShape);
	               	vec.push_back(rec);
                    temp2 += recb.get_width();
                }
            temp2 = recb.get_width();
            temp1 +=recb.get_height();

            }

     
    }
    else if(main_shape ==1 && small_shape == 2){
        
        int point_x=0;
    
        int  point_y = pow(tri_b.get_length(),2) - pow((tri_b.get_length()/2),2);
        point_y = sqrt(point_y);
        int y = point_y;
        int point3_x = tri_b.get_length()/2;
        int point3_y=0;
        int triangle_counter = 0;


        while(point_y <= reca.get_height()){
            while(point_x <= reca.get_width() - tri_b.get_length()/2){
               shape* newShape = new triangle(tri_b.get_length(),point_x,point_y,point_x+tri_b.get_length(),point_y,point3_x,point3_y );
               triangle *tri = dynamic_cast<triangle*>(newShape);
               vec.push_back(tri);

                if(point3_x+tri_b.get_length() < reca.get_width()){
                    shape* newShape = new triangle(tri_b.get_length(),point_x,point_y,point_x+tri_b.get_length(),point_y,point3_x,point3_y );
    		        triangle *tri = dynamic_cast<triangle*>(newShape);
	                vec.push_back(tri);
        
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
        

        int temp_height = cir_b.get_radius();
        int temp_width = cir_b.get_radius();

            while(temp_height <= reca.get_height()-cir_b.get_radius()){
                while(temp_width <=reca.get_width()-cir_b.get_radius()){
                	
                	shape* newShape = new circle(cir_b.get_radius(),temp_width,temp_height);
    		        circle *cir = dynamic_cast<circle*>(newShape);
	                vec.push_back(cir);
        
                    temp_width += 2*cir_b.get_radius();
                }

            temp_width =cir_b.get_radius();
            temp_height += 2*cir_b.get_radius();
            }
    }
    else if(main_shape == 3 && small_shape == 1){
         
         int point1_x=cir_a.get_radius() - recb.get_width()/2;
        int point1_y=cir_a.get_radius()-recb.get_height() /2;
        int point2_x=cir_a.get_radius()-recb.get_width()/2;
        int point2_y=cir_a.get_radius()-recb.get_height()/2;
        int temp = (2*cir_a.get_radius()) / recb.get_width();
        int temp2 = 0;
        int circle_counter =0;
        
        while(point1_y >= 0 && point2_y <= 2*cir_a.get_radius()){
            while(point1_x >= 0 && point2_x <= 2*cir_a.get_radius() &&temp2 < temp){
            	shape *newShape = new rectangle(recb.get_width(),recb.get_height(),point1_x,point1_y);
               	rectangle *rec = dynamic_cast<rectangle*>(newShape);
               	vec.push_back(rec);

                shape *newShape1 = new rectangle(recb.get_width(),recb.get_height(),point2_x,point2_y);
               	rectangle *rec1 = dynamic_cast<rectangle*>(newShape1);
               	vec.push_back(rec1);
               	
               	shape *newShape2 = new rectangle(recb.get_width(),recb.get_height(),point1_x,point2_y);
               	rectangle *rec2 = dynamic_cast<rectangle*>(newShape2);
               	vec.push_back(rec2);
                
                shape *newShape3 = new rectangle(recb.get_width(),recb.get_height(),point2_x,point1_y);
               	rectangle *rec3 = dynamic_cast<rectangle*>(newShape3);
               	vec.push_back(rec3);
                
                
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
    
        double triangle_height = pow(tri_a.get_length(),2)-pow(tri_a.get_length()/2,2);
        triangle_height=sqrt(triangle_height);
        double point1_x = (1/sqrt(3))*recb.get_height();
        double temp_point_x=point1_x;
        double point1_y = triangle_height-recb.get_height();
        double counter = tri_b.get_length() / recb.get_height();
        int counter2 = 0;
        int counter3 =1;
        double temp_triangle_length =tri_a.get_length();
        
        while(point1_y >= 0.0){
        while(point1_x+recb.get_width() < temp_triangle_length-(2*temp_point_x)){

            shape* newShape = new rectangle(recb.get_width(),recb.get_height(),point1_x,point1_y);    
           rectangle* rec = dynamic_cast<rectangle*>(newShape);

           vec.push_back(rec);
        
            point1_x += recb.get_width();
            counter2++;
    
        }
    counter3++;
    point1_x = (1/sqrt(3))*recb.get_height();
    point1_x *=counter3;
    
    point1_y -= recb.get_height();
    temp_triangle_length -= recb.get_height()/2;
    counter = temp_triangle_length/recb.get_width();
    }

    }
    else if(main_shape == 3 && small_shape == 3){
         
        int temp_num1 = cir_a.get_radius();
        int temp_num2 = cir_a.get_radius();
        int temp_num3 = cir_a.get_radius();
        int temp_num4 = cir_a.get_radius();
        int counter2 =0;
        int counter3 =0;
        int counter = 2*cir_a.get_radius() / (cir_b.get_radius() * 2);
        while (temp_num3 > cir_b.get_radius()){

            while(temp_num1 >  cir_b.get_radius()&& counter2 < counter ){
                counter3++;
                shape * newShape = new circle(cir_b.get_radius(),temp_num1,temp_num3);
                circle *cir = dynamic_cast<circle*>(newShape);
                vec.push_back(cir); 
                
                
                shape * newShape1 = new circle(cir_b.get_radius(),temp_num2,temp_num3);
                circle *cir2 = dynamic_cast<circle*>(newShape1);
                vec.push_back(cir2); 
                
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
        //delete cir;
        temp_num1 = cir_a.get_radius();
        temp_num2 = cir_a.get_radius();
        temp_num3 = cir_a.get_radius();
        temp_num4 = cir_a.get_radius();
        counter =2* cir_a.get_radius() / (cir_b.get_radius() * 2);
        counter2=0;
        while (temp_num3 < 2*cir_a.get_radius() - cir_b.get_radius()){

            while(temp_num1 > cir_b.get_radius() && counter2 < counter ){
                counter3++;
                shape * newShape = new circle(cir_b.get_radius(),temp_num1,temp_num3);
                circle *cir = dynamic_cast<circle*>(newShape);
                vec.push_back(cir); 
                
                shape * newShape1 = new circle(cir_b.get_radius(),temp_num2,temp_num3);
                circle *cir1 = dynamic_cast<circle*>(newShape1);
                vec.push_back(cir1); 
                
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
    
shape& composedShape::operator[](const int index){
	return *vec[index];
}