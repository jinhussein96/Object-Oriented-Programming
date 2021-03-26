#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


using namespace std;

class Circle{
private:
    int radius;
    int cir_x,cir_y;
public:
    Circle(): radius(0),cir_x(0),cir_y(0) {};
    Circle(int rds) :radius(rds){};
    Circle(int rds , int x , int y) :radius(rds),cir_x(x),cir_y(y){};
    void set_radius(int rds,int point_x,int point_y);
    int get_radius() const;
    int get_point_x()const{return cir_x;}
    int get_point_y()const{return cir_y;}
    void draw(ofstream& file)const;
    int area(){return 3.14 * radius *radius ;}

};

class Rectangle{
private:
    int width,height;
    int temp_width , temp_height;

public:

    Rectangle():width(0) , height(0),temp_width(0),temp_height(0) {};
    Rectangle(int w,int h, int temp_w,int temp_h ):width(w) , height(h),temp_width(temp_w),temp_height(temp_h) {};
    void set_dimensions(int hght,int wdth,int x,int y);
    int get_wdth() const ;
    int get_hght() const ;
    int get_temp_wdth()const {return temp_width;}
    int get_temp_hght()const{return temp_height;}
    void draw(ofstream& file)const;
    int area(){return width*height;}
    int small_area(){return temp_width*temp_height;}

};


class Triangle{
private:
    int length;
    int point_a_x,point_a_y , point_b_x,point_b_y , point_c_x,point_c_y ;
public:
    Triangle(): length(0),point_a_x(0),point_a_y(0), point_c_x(0),point_c_y(0),point_b_y(0),point_b_x(0) {};
    Triangle(int len):length(len){};
    void set_len(int len);
    void set_points(int point_A_x,int point_A_y ,int point_B_x,int point_B_y ,int point_C_x,int point_C_y);
    int get_len() const {return length;};
    int get_point_a_x()const{return point_a_x;}
    
    int get_point_a_y()const{return point_a_y;}
    int get_point_b_x()const{return point_b_x;}
    int get_point_b_y()const{return point_b_y;}
    int get_point_c_x()const{return point_c_x;}
    int get_point_c_y()const{return point_c_y;}
    void draw(ofstream& file) const;



};

class composedSahpe{
private:
    Rectangle reca , recb; //shape = 1
    Triangle tri_a,tri_b;//shape = 2
    Circle cir_a,cir_b;//shape = 3
    int main_shape,small_shape;
public:
    composedSahpe();
    composedSahpe(Rectangle container_rec,Rectangle inner_rec) :reca(container_rec) ,recb(inner_rec){};
    composedSahpe(Rectangle container_rec , Circle inner_cir): reca(container_rec),cir_b(inner_cir){};
    composedSahpe(Rectangle container_rec, Triangle inner_tri):reca(container_rec),tri_b(inner_tri){};
    composedSahpe(Circle container_cir , Rectangle inner_rec):cir_a(container_cir),recb(inner_rec){};
    composedSahpe(Circle container_cir , Triangle inner_tri):cir_a(container_cir),tri_b(inner_tri){};
    composedSahpe(Circle container_cir,Circle inner_cir):cir_a(container_cir),cir_b(inner_cir){};
    composedSahpe(Triangle container_tri , Triangle inner_tri):tri_a(container_tri),tri_b(inner_tri){};
    composedSahpe(Triangle container_tri,Rectangle inner_rec):tri_a(container_tri),recb(inner_rec){};
    composedSahpe(Triangle container_tri , Circle inner_cir):tri_a(container_tri),cir_b(inner_cir){};
    void set_shapes(int mainShape,int smallShape) ;
    void optimalFit(int main_shape,int small_shape);
    vector<Rectangle> rec_vector;
    vector<Circle> cir_vector;
    vector<Triangle> tri_vector;
    void draw_rec(ofstream& file);
    void draw_tri(ofstream& file);
    void draw_cir(ofstream& file);
};


void Triangle::set_points(int point_A_x,int point_A_y ,int point_B_x,int point_B_y ,int point_C_x,int point_C_y){
	point_a_x = point_A_x;
	point_a_y = point_A_y;
	point_b_x = point_B_x;
	point_b_y = point_B_y;
	point_c_x = point_C_x;
	point_c_y = point_C_y ; 




}

void Triangle::set_len(int len){
	length = len;
}

void Triangle::draw(ofstream& myfile)const{
    myfile<<"<path d=\"M"<<point_a_x<<" "<<point_a_y<<" L"<<point_b_x<<" "<<point_b_y<<" L"<<point_c_x <<" "<< point_c_y<<" Z \" stroke=\"green\" stroke-width=\"1\" fill=\"pink\" /> \n" ;
    myfile<<endl;
}



void Rectangle::set_dimensions(int hght,int wdth,int x,int y){

    width = wdth;
    height = hght;
    temp_width = x;
    temp_height = y;

}
int Rectangle::get_wdth() const{
    return width;
}



int  Rectangle::get_hght() const {
    return height;

}



void Rectangle::draw(ofstream& myfile)const{
    char c = '"';

   myfile << "<rect x=\""<<width<<"\" y=\""<<height<<"\" width= "<< c <<temp_width<< c << " height= " << c<<temp_height<< c<<endl ;
            
    myfile<< "style =\"fill:blue;stroke-width:2;stroke:black\" />"<<endl;       
}


void composedSahpe::set_shapes(int mainShape,int smallShape){
    main_shape = mainShape;
    small_shape=smallShape;
}

void composedSahpe::optimalFit(int main_shape,int small_shape){
    
    if(main_shape == 1 && small_shape == 1){ //small shape is rectangle
       Rectangle rec_c;
        int temp1 , temp2;
        temp1 = recb.get_temp_hght();
        temp2 = recb.get_temp_wdth();
        while(temp1 < reca.get_temp_hght()){
            while(temp2 < reca.get_temp_wdth()){
                rec_c.set_dimensions(temp2,temp1,recb.get_temp_wdth(),recb.get_temp_hght());
                    
                rec_vector.push_back(rec_c);
                temp2 += recb.get_temp_wdth();
            }
        temp2 = recb.get_temp_wdth();
        temp1 +=recb.get_temp_hght();

        }
    }//
    else if(main_shape == 1 && small_shape == 2){
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
                tri_vector.push_back(tri_c);
                
                if(point3_x+tri_b.get_len() < reca.get_wdth()){
                    tri_c.set_points(point3_x,point3_y,point_x+tri_b.get_len(),point_y,point3_x+tri_b.get_len(),point3_y );
                    tri_vector.push_back(tri_c);        
                }
                point_x += tri_b.get_len();
                point3_x += tri_b.get_len();
            
        
            }
            point_x = 0;
            point3_x = tri_b.get_len()/2;
            point3_y += y;
            point_y += y;
        }



    }//


    
    else if (main_shape == 1 && small_shape == 3){
        Circle cir;

        int temp_height = cir_b.get_radius();
        int temp_width = cir_b.get_radius();
        while(temp_height <= reca.get_hght()-cir_b.get_radius()){
        while(temp_width <=reca.get_wdth()-cir_b.get_radius()){

            cir.set_radius(cir_b.get_radius(),temp_width,temp_height);
            cir_vector.push_back(cir);
            temp_width += 2*cir_b.get_radius();
        }

        temp_width =cir_b.get_radius();
        temp_height += 2*cir_b.get_radius();
    }
    }
    else if(main_shape == 2 && small_shape == 1){
        Rectangle rec_c;
        int triangle_height = pow(tri_a.get_len(),2)-pow(tri_a.get_len()/2,2);
        triangle_height=sqrt(triangle_height);
        int point1_x = (1/sqrt(3))*recb.get_hght();
        int temp_point_x=point1_x;
        int point1_y = triangle_height-recb.get_hght();
        int counter = tri_b.get_len() / recb.get_hght();
        int counter2 = 0;
        int counter3 =1;
        int temp_triangle_length =tri_a.get_len();
        
        while(point1_y >= 0){
        while(point1_x+recb.get_wdth() < temp_triangle_length){

            rec_c.set_dimensions(point1_y,point1_x,recb.get_wdth(),recb.get_hght());    
            rec_vector.push_back(rec_c);
        
            point1_x += recb.get_wdth();
            counter2++;
    
        }
    counter3++;
    point1_x = (1/sqrt(3))*recb.get_hght()/2;
    point1_x += counter3*temp_point_x;
    
    point1_y -= recb.get_temp_hght();
    temp_triangle_length -= recb.get_hght()/2;
    counter = temp_triangle_length/recb.get_wdth();
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
            rec_c.set_dimensions(point1_x,point1_y,recb.get_wdth(),recb.get_hght());
            rec_vector.push_back(rec_c);
            rec_c.set_dimensions(point2_x,point2_y,recb.get_wdth(),recb.get_hght());
            rec_vector.push_back(rec_c);
            rec_c.set_dimensions(point1_x,point2_y,recb.get_wdth(),recb.get_hght());
            rec_vector.push_back(rec_c);
            rec_c.set_dimensions(point2_x,point1_y,recb.get_wdth(),recb.get_hght());
            rec_vector.push_back(rec_c);
            
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
                cir_vector.push_back(cir);
                cir.set_radius(cir_b.get_radius(),temp_num2,temp_num3);
                cir_vector.push_back(cir);
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
            cir.set_radius(cir_b.get_radius(),temp_num1,temp_num3);
            cir_vector.push_back(cir);
            cir.set_radius(cir_b.get_radius(),temp_num2,temp_num3);
            cir_vector.push_back(cir);
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
void Circle::set_radius(int rds,int point_x,int point_y){
    radius = rds;
    cir_x = point_x;
    cir_y = point_y;
}

int Circle::get_radius()const{
	return radius;
}
void Circle::draw(ofstream& file)const{

   file <<"<circle cx = \""<<cir_x<<"\" cy=\""<<cir_y<<"\" r=\""<<radius<<"\" fill= \"red\" stroke=\"black\" stroke-width=\"3\" />" ;
   file<<endl;

}

void composedSahpe::draw_rec(ofstream& myfile){
    for(int i = 0 ; i < rec_vector.size();i++){
        rec_vector[i].draw(myfile);
    }

}
void composedSahpe::draw_cir(ofstream& myfile){
    for(int i=0;i<cir_vector.size();i++){
        cir_vector[i].draw(myfile);
    }
}
void composedSahpe::draw_tri(ofstream& myfile){
    for(int i=0;i<tri_vector.size();i++){
        tri_vector[i].draw(myfile);
    }
}

int main()
{
    ofstream myfile("output.svg");
   if(!myfile){
    cout <<"sorry couldnt open file \n";
   }
    Rectangle reca , recb;
    Circle cir_a,cir_b;
    Triangle tri_a,tri_b;
    
    char shape;
    char small_shape;
    cout << "Please enter the main container shape (R, C, T) "<< endl ;
    cin >> shape ;
    cout <<"please enter the small shape (R,C,T)" << endl;
    cin >> small_shape;
    int width , height;
    int small_width,small_height;
    int radius;
    char c = '"';
    int length;
    if(shape == 'R'){
        cout << "please enter the width and height of the main rectangle" <<endl;
        cout << "enter the width " ;
        cin >> width ;
        cout << "enter the height ";
        cin >> height;
        myfile <<" <svg width= " << c<< width<<c << " height= " << c << height << c << ">" <<endl ;

        reca.set_dimensions(width ,height,width,height);
        reca.draw(myfile);
            if(small_shape == 'R'){
                
                cout << "please enter the width and height of the inner rectangle" <<endl;
                cout << "enter the width " ;
                cin >> small_width ;
                cout << "enter the height ";
                cin >> small_height;
                recb.set_dimensions(small_width,small_height,small_width,small_height);
                composedSahpe com(reca,recb);
                com.set_shapes(1,1);
                com.optimalFit(1,1);
                com.draw_rec(myfile);

            }
            else if(small_shape == 'C'){
                cout <<"please enter the radius of the small shape \n";
                cin >> radius ;

                cir_b.set_radius(radius,radius,radius);
                composedSahpe com(reca,cir_b);
                com.set_shapes(1,3);
                com.optimalFit(1,3);
                com.draw_cir(myfile);

            }
            else if(small_shape == 'T'){
                cout <<"please enter the length of the triangle side ";
                cin >> length;
                tri_b.set_len(length);
                 composedSahpe com(reca,tri_b);
                 com.set_shapes(1,2);
                com.optimalFit(1,2);
                com.draw_tri(myfile);

            }

    }
    else if(shape == 'C'){
        cout <<"please enter the radius of the main shape \n";
        cin >> radius ;
        myfile <<"<svg> \n" ;
        cir_a.set_radius(radius,radius,radius);
        cir_a.draw(myfile);
        if(small_shape == 'R'){


                cout << "please enter the width and height of the inner rectangle" <<endl;
                cout << "enter the width " ;
                cin >> small_width ;
                cout << "enter the height ";
                cin >> small_height;
                recb.set_dimensions(small_height,small_width,0,0);
                composedSahpe com(cir_a,recb);
                com.set_shapes(3,1);
                com.optimalFit(3,1);
                com.draw_rec(myfile);


        }
        else if(small_shape == 'C'){
            cout <<"please enter the radius of the small shape \n";
             cin >> radius ;
             cir_b.set_radius(radius,radius,radius);
            composedSahpe com(cir_a,cir_b);
                com.set_shapes(3,3);
                com.optimalFit(3,3);
                com.draw_cir(myfile);

        }
    }
    else if(shape == 'T'){
        cout <<"please enter the length of the main triangle's side \n";
        cin >> length;
        myfile <<"<svg> \n";
        tri_a.set_len(length);
        tri_a.set_points(0,(sqrt(3)/2)*tri_a.get_len(),tri_a.get_len(),(sqrt(3)/2)*tri_a.get_len(),tri_a.get_len()/2,0);
        tri_a.draw(myfile);
        if(small_shape == 'R'){
            cout << "please enter the width and height of the inner rectangle" <<endl;
            cout << "enter the width " ;
            cin >> small_width ;
            cout << "enter the height ";
            cin >> small_height;
            recb.set_dimensions(small_width,small_height,small_width,small_height);
             composedSahpe com(tri_a,recb);
                com.set_shapes(2,1);
                com.optimalFit(2,1);
                com.draw_rec(myfile);
        }


    }

    myfile<<"</svg>";
   myfile.close();
   return 0;
}
