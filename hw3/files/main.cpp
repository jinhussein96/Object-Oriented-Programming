#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
 
#include "composedShape.h"
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include "polygon.h"
#include "polyvec.h"
#include "polydyn.h"
using namespace std;
using namespace hw5;
ofstream& operator <<(ofstream& file , shape* shape1){
		 shape1->draw(file);

		return file ;
}
void printAll(ofstream& myfile,vector<shape*> vec){
	for(int i = 0 ; i < vec.size();i++){
		myfile<<vec[i];
		
	}
}
void printpoly(ofstream& myfile,vector<shape*> vec){
	for(int i = 0 ; i < vec.size();i++){
		vec[i]->draw(myfile);
		
	}
}

void sortShapes(std::vector<shape*>& v){
	shape* temp;
	for(int i = 0 ; i < v.size(); i++){
		for(int j = 0 ; j < v.size();j++){
			if(v[i]->area() < v[j]->area()){
			    temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}
		
}



int main(){
	ofstream myfile;
	myfile.open("output.svg");
	if(!myfile){
    cout <<"sorry couldnt open file \n";
   }
  
  	char shape;
    char small_shape;
    rectangle reca,recb;
    circle cir_a,cir_b;
    triangle tri_a,tri_b;


    cout << "Please enter the main container shape (R, C, T) "<< endl ;
    cin >> shape ;
    cout <<"please enter the small shape (R,C,T)" << endl;
    cin >> small_shape;

     if(shape == 'R' ){
       double width,height;
        char c= '"';
        int small_width,small_height;
        cout << "please enter the width and height of the main rectangle" <<endl;
        cout << "enter the width " ;
        cin>>width;
        cout<<"please enter the height ";
        cin >> height;
        myfile <<" <svg width= " << c<< width<<c << " height= " << c << height << c << ">" <<endl ;
       	reca.set_dimentions(width,height,0,0);
       	polyvec *p = new polyvec(reca);
       	myfile<< p;
       	if(small_shape == 'R'){

            cout << "please enter the width and height of the inner rectangle" <<endl;
            cout << "enter the width " ;
            cin >> small_width ;
            cout << "enter the height ";
            cin >> small_height;
            recb.set_dimentions(small_width,small_height,0,0);
            polyvec *p1 = new polyvec(recb);
            composedShape *com = new composedShape(reca,recb);
            printAll(myfile,com->get_vector());
        }
        else if(small_shape == 'T'){
            double length;
            cout <<"please enter the length of the triangle side ";
            cin >> length;
            tri_b.set_length(length);

            composedShape *com = new composedShape(reca,tri_b);
            printAll(myfile,com->get_vector());
        }
         else if(small_shape == 'C'){
            double radius;
            cout <<"please enter the radius of the small shape \n";
            cin >> radius ;

            cir_b.set_radius(radius,radius,radius);
         	composedShape *com = new composedShape(reca,cir_b);
            printAll(myfile,com->get_vector());
             
           
                
        }
      
    }
    else if(shape == 'C'){
        double radius;
        cout <<"please enter the radius of the main shape \n";
        cin >> radius ;
        myfile <<"<svg> \n" ;
        circle cir_a(radius,radius,radius);
        polyvec *p = new polyvec(cir_a);
        myfile<<p;
        if(small_shape == 'R'){
            double small_width,small_height;
            cout << "please enter the width and height of the inner rectangle" <<endl;
            cout << "enter the width " ;
            cin >> small_width ;
            cout << "enter the height ";
            cin >> small_height;
            recb.set_dimentions(small_width,small_height,radius,radius);
            composedShape *com = new composedShape(cir_a,recb);
            printAll(myfile,com->get_vector());
                
        }
        else if(small_shape == 'C'){
            double radius;
            cout <<"please enter the radius of the small shape \n";
            cin >> radius ;

            cir_b.set_radius(radius,cir_a.get_radius(),cir_a.get_radius());
            composedShape *com = new composedShape(cir_a,cir_b);
            printAll(myfile,com->get_vector());
                
                
        }
 	    
             


}
else if(shape == 'T'){
        double length;
        double small_height,small_width;
        cout <<"please enter the length of the main triangle's side \n";
        cin >> length;
        myfile <<"<svg> \n";
        tri_a.set_length(length);
        tri_a.set_points(0,(sqrt(3)/2)*tri_a.get_length(),tri_a.get_length(),(sqrt(3)/2)*tri_a.get_length(),tri_a.get_length()/2,0);
       	polyvec *p = new polyvec(tri_a);
       	myfile<< p ;
       	if(small_shape == 'R'){
            cout << "please enter the width and height of the inner rectangle" <<endl;
            cout << "enter the width " ;
            cin >> small_width ;
            cout << "enter the height ";
            cin >> small_height;
            recb.set_dimentions(small_width,small_height,tri_a.get_length()/2,tri_a.get_length()/2);
            composedShape *com = new composedShape(tri_a,recb);
            printAll(myfile,com->get_vector());
            
         }
              

}




   
    myfile<<"</svg>";


   
		return 0;
}
