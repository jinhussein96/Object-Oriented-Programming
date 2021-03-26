#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "composedShape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

//using namespace std;
//enum class type { Rectangle ,Triangle,Circle};
typedef composedSahpe::shapeElem lem;

composedSahpe:: composedSahpe(ofstream& file,Rectangle container_rec,Rectangle inner_rec){
    reca = container_rec;
    recb = inner_rec;
    lem a(reca);

    lem b(recb);

    lem_vec.push_back(a);
    lem_vec.push_back(b);
  
    optimalFit(1,1);


}
composedSahpe::composedSahpe(ofstream& file , Rectangle container_rec,Triangle inner_tri){
    reca = container_rec;
    tri_b = inner_tri;
    lem a(reca);
    lem b(tri_b);
    lem_vec.push_back(a);
    lem_vec.push_back(b);
    optimalFit(1,2);
    draw_tri(file);
}
composedSahpe::composedSahpe(ofstream& file,Rectangle container_rec,Circle inner_cir){
    reca = container_rec;
    cir_b = inner_cir;
    lem a(reca);
    lem b(cir_b);
    lem_vec.push_back(a);
    lem_vec.push_back(b);
    optimalFit(1,3);
    draw_cir(file);
}
composedSahpe::composedSahpe(ofstream& file,Circle container_cir,Rectangle inner_rec){
    cir_a = container_cir;
    recb = inner_rec;
    lem a(cir_a);
    lem b(recb);
    lem_vec.push_back(a);
    lem_vec.push_back(b);
    optimalFit(3,1);
    draw_rec(file);
}
composedSahpe::composedSahpe(ofstream& file,Circle container_cir,Circle inner_cir){
    cir_a = container_cir;
    cir_b = inner_cir;
    lem a(cir_a);
    lem b(cir_b);
    lem_vec.push_back(a);
    lem_vec.push_back(b);
    optimalFit(3,3);
    draw_cir(file);
}
composedSahpe::composedSahpe(ofstream& file,Triangle container_tri,Rectangle inner_rec){
    tri_a = container_tri;
    recb = inner_rec;
    optimalFit(2,1);
    draw_rec(file);
}
composedSahpe::composedSahpe(ofstream& file,Triangle container_tri,Circle inner_cir){
    tri_a = container_tri;
    cir_b = inner_cir;
    lem a(tri_a);
    lem b(cir_b);
    lem_vec.push_back(a);
    lem_vec.push_back(b);
    optimalFit(2,3);
    draw_cir(file);
}
composedSahpe::composedSahpe(ofstream& file,Triangle container_tri,Triangle inner_tri){
    tri_a = container_tri;
    tri_b = container_tri;
    lem a(tri_a);
    lem b(tri_b);
    lem_vec.push_back(a);
    lem_vec.push_back(b);
    optimalFit(2,2);
    draw_tri(file);
}
void composedSahpe::draw_cir(ofstream& myfile){
    for(int i=0;i<cir_vector.size();i++){
        myfile<<cir_vector[i];
    }
}
void composedSahpe::draw_tri(ofstream& myfile){
    for(int i=0;i<tri_vector.size();i++){
        myfile<<tri_vector[i];
    }
}

void composedSahpe::draw_rec(ofstream& myfile){
    for(int i = 0 ; i < rec_vector.size();i++){
        myfile<<rec_vector[i];
    }

}
void composedSahpe::optimalFit(int main_shape,int small_shape){

    if(main_shape ==1 && small_shape == 1){
        
             Rectangle rec_c;
            int temp1 , temp2;
            temp1 = recb.get_hght();
            temp2 = recb.get_wdth();
            cout<< temp1 <<endl;
            cout<< temp2 <<endl;
            
            while(temp1 < reca.get_hght()){

               while(temp2 < reca.get_wdth()){
                    rec_c.set_dimensions(recb.get_wdth(),recb.get_hght(),temp2,temp1);
                    lem *a=new lem(rec_c);   
                    *this += *a;
                    temp2 += recb.get_wdth();
                }
            temp2 = recb.get_wdth();
            temp1 +=recb.get_hght();

            }

     
    }
    else if(main_shape ==1 && small_shape == 2){
        Triangle tri_c;
        int point_x=0;
    
        int  point_y = pow(tri_b.get_len(),2) - pow((tri_b.get_len()/2),2);
        point_y = sqrt(point_y);
        int y = point_y;
        int point3_x = tri_b.get_len()/2;
        int point3_y=0;
        int triangle_counter = 0;


        while(point_y <= reca.get_hght()){
            while(point_x <= reca.get_wdth() - tri_b.get_len()/2){
                tri_c.set_points(point_x,point_y,point_x+tri_b.get_len(),point_y,point3_x,point3_y );
                lem *b=new lem(tri_c);   
                *this += *b;
                if(point3_x+tri_b.get_len() < reca.get_wdth()){
                    tri_c.set_points(point3_x,point3_y,point_x+tri_b.get_len(),point_y,point3_x+tri_b.get_len(),point3_y );
                    lem *c=new lem(tri_c);   
                    *this += *c;        
                }
                point_x += tri_b.get_len();
                point3_x += tri_b.get_len();
            
        
            }
            point_x = 0;
            point3_x = tri_b.get_len()/2;
            point3_y += y;
            point_y += y;
        }
    }
    else if(main_shape == 1 && small_shape == 3){
        Circle cir;

        int temp_height = cir_b.get_radius();
        int temp_width = cir_b.get_radius();
            while(temp_height <= reca.get_hght()-cir_b.get_radius()){
                while(temp_width <=reca.get_wdth()-cir_b.get_radius()){

                    cir.set_radius(cir_b.get_radius(),temp_width,temp_height);
                    lem *s=new lem(cir);   
                    *this += *s;
                    temp_width += 2*cir_b.get_radius();
                }

            temp_width =cir_b.get_radius();
            temp_height += 2*cir_b.get_radius();
            }
    }
    else if(main_shape == 3 && small_shape == 1){
         Rectangle rec_c;
         int point1_x=cir_a.get_radius() - recb.get_wdth()/2;
        int point1_y=cir_a.get_radius()-recb.get_hght() /2;
        int point2_x=cir_a.get_radius()-recb.get_wdth()/2;
        int point2_y=cir_a.get_radius()-recb.get_hght()/2;
        int temp = (2*cir_a.get_radius()) / recb.get_wdth();
        int temp2 = 0;
        int circle_counter =0;
        
        while(point1_y >= 0 && point2_y <= 2*cir_a.get_radius()){
            while(point1_x >= 0 && point2_x <= 2*cir_a.get_radius() &&temp2 < temp){
                rec_c.set_dimensions(recb.get_wdth(),recb.get_hght(),point1_x,point1_y);
                lem *x=new lem(rec_c);   
                    *this += *x;
                rec_c.set_dimensions(recb.get_wdth(),recb.get_hght(),point2_x,point2_y);
                 lem *f=new lem(rec_c);   
                    *this += *f;
                rec_c.set_dimensions(recb.get_wdth(),recb.get_hght(),point1_x,point2_y);
                 lem *p=new lem(rec_c);   
                    *this += *p;
                rec_c.set_dimensions(recb.get_wdth(),recb.get_hght(),point2_x,point1_y);
                 lem *a=new lem(rec_c);   
                    *this += *a;
                
                    temp2++;
                point1_x -= recb.get_wdth();
                point2_x += recb.get_wdth();    
            }
            
            temp -= 2;
            temp2 = 0;

            point1_x=cir_a.get_radius()-recb.get_wdth()/2;
            point2_x=cir_a.get_radius()-recb.get_wdth()/2;
            point1_y -= recb.get_hght();
            point2_y += recb.get_hght();

                        
        } 
    }
    else if(main_shape == 2 && small_shape ==1){
        Rectangle rec_c;
        double triangle_height = pow(tri_a.get_len(),2)-pow(tri_a.get_len()/2,2);
        triangle_height=sqrt(triangle_height);
        double point1_x = (1/sqrt(3))*recb.get_hght();
        double temp_point_x=point1_x;
        double point1_y = triangle_height-recb.get_hght();
        double counter = tri_b.get_len() / recb.get_hght();
        int counter2 = 0;
        int counter3 =1;
        double temp_triangle_length =tri_a.get_len();
        
        while(point1_y >= 0.0){
        while(point1_x+recb.get_wdth() < temp_triangle_length-(2*temp_point_x)){

            rec_c.set_dimensions(recb.get_wdth(),recb.get_hght(),point1_x,point1_y);    
            lem *q=new lem(rec_c);   
            *this += *q;
        
            point1_x += recb.get_wdth();
            counter2++;
    
        }
    counter3++;
    point1_x = (1/sqrt(3))*recb.get_hght();
    point1_x *=counter3;
    
    point1_y -= recb.get_hght();
    temp_triangle_length -= recb.get_hght()/2;
    counter = temp_triangle_length/recb.get_wdth();
    }

    }
    else if(main_shape == 3 && small_shape == 3){
         Circle cir;
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
                cir.set_radius(cir_b.get_radius(),temp_num1,temp_num3);
                lem *s=new lem(cir);   
                *this += *s;
        
                 Circle cir(cir_b.get_radius());
                cir.set_radius(cir_b.get_radius(),temp_num2,temp_num3);
                lem *h=new lem(cir);   
                *this += *h;
        
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
                cir.set_radius(cir_b.get_radius(),temp_num1,temp_num3);
                lem *a=new lem(cir);   
                *this += *a;
        
                cir.set_radius(cir_b.get_radius(),temp_num2,temp_num3);
                lem *y=new lem(cir);   
                *this += *y;
        
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

composedSahpe& composedSahpe::operator+=(shapeElem& shape){
    this->lem_vec.push_back(shape);
    return *this;
}
ofstream& operator<<(ofstream& myfile , composedSahpe& com){
    for(int i =0 ; i < com.lem_vec.size();i++){
        myfile<< &com.lem_vec[i];
        cout<<"1\n";

    }
    return myfile;

}
//////////////////////////////////////////////////////////////////////////////////////

lem::shapeElem(Rectangle& rec){
    pointer = &rec;
    set_shape(Rec);
}
lem::shapeElem(Circle& cir){
    pointer = &cir;
    set_shape(Cir);
}
lem::shapeElem(Triangle& tri){
    pointer = &tri;
    set_shape(Tri);
}
 double lem::get_length()const{
    Triangle *temp_tri = (static_cast<Triangle*>(pointer));
    return temp_tri->get_len();
}
double lem::get_radius()const{
    Circle *temp_cir = static_cast<Circle*>(pointer);
    return temp_cir->get_radius();
}
 double lem::get_rec_wdth()const{
    Rectangle *temp_rec = static_cast<Rectangle*>(pointer);
    return temp_rec->get_wdth();
}
double lem::get_rec_hght()const{
    Rectangle *temp_rec = static_cast<Rectangle*>(pointer);
    return temp_rec->get_hght();
}
 const double lem::get_area()const{
    if(shape == Rec){
        Rectangle *rec = static_cast<Rectangle*>(pointer);
        return rec->get_area();
    }
    else if(shape == Tri){
        Triangle *tri = static_cast<Triangle*>(pointer);
        return tri->get_area();
    }
    else if(shape == Cir){
        Circle *cir = static_cast<Circle*>(pointer);
        return cir->get_area();
    }
}
const double lem::get_perimeter()const{
    if(shape == Rec){
        Rectangle *rec = static_cast<Rectangle*>(pointer);
        return rec->get_perimeter();
    }
     else if(shape == Tri){
        Triangle *tri = static_cast<Triangle*>(pointer);
        return tri->get_perimeter();
    }
    else if(shape == Cir){
        Circle *cir = static_cast<Circle*>(pointer);
        return cir->get_perimeter();
    }
 }
 ofstream& operator<<(ofstream& myfile,lem& shape ){
    if(shape.shape == Rec){
        Rectangle *rec = reinterpret_cast<Rectangle*>(shape.pointer);
        myfile<< *rec;
        return myfile;
    }
    else if(shape.shape == Cir){
        Circle *cir = reinterpret_cast<Circle*>(shape.pointer);
        myfile<< *cir;
        return myfile;
    }
    else if(shape.shape == Tri){
        Triangle *tri = reinterpret_cast<Triangle*>(shape.pointer);
        myfile<< *tri;
        return myfile;
    }
 }