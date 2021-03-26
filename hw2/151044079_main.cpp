#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


#include "composedShape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
using namespace std;

int main(){
    Rectangle reca,recb;
    Circle cir_a,cir_b;
    Triangle tri_a,tri_b;


    ofstream myfile("output.svg");
   if(!myfile){
    cout <<"sorry couldnt open file \n";
   }


    char shape;
    char small_shape;


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
        reca.set_dimensions(width,height,0,0);
        myfile<<reca;
        if(small_shape == 'R'){

            cout << "please enter the width and height of the inner rectangle" <<endl;
            cout << "enter the width " ;
            cin >> small_width ;
            cout << "enter the height ";
            cin >> small_height;
            recb.set_dimensions_for_small_shape(small_width,small_height);
            composedSahpe com(myfile,reca,recb);
        }
        else if(small_shape == 'T'){
            double length;
            cout <<"please enter the length of the triangle side ";
            cin >> length;
            tri_b.set_len(length);
            composedSahpe com(myfile,reca,tri_b);
        }
        else if(small_shape == 'C'){
            double radius;
            cout <<"please enter the radius of the small shape \n";
            cin >> radius ;

            cir_b.set_radius(radius,radius,radius);
            composedSahpe com(myfile,reca,cir_b);

                
        }


    }
    else if(shape == 'C'){
        double radius;
        cout <<"please enter the radius of the main shape \n";
        cin >> radius ;
        myfile <<"<svg> \n" ;
        Circle cir_a(radius,radius,radius);
        cir_a.set_area(radius);
        //cir_a.draw(myfile);
        myfile<<cir_a;
        Circle ciiir = cir_a + 5;
        ciiir.set_area(ciiir.get_radius());
        cout << ciiir.get_area() <<"  "<< ciiir.get_radius();
        if(small_shape == 'R'){
            double small_width,small_height;
            cout << "please enter the width and height of the inner rectangle" <<endl;
            cout << "enter the width " ;
            cin >> small_width ;
            cout << "enter the height ";
            cin >> small_height;
            recb.set_dimensions_for_small_shape(small_width,small_height);
            composedSahpe com(myfile,cir_a,recb);
                
        }
        else if(small_shape == 'C'){
            double radius;
            cout <<"please enter the radius of the small shape \n";
            cin >> radius ;

            cir_b.set_radius(radius,radius,radius);
            composedSahpe com(myfile,cir_a,cir_b);
            cout<<Circle::get_total_area();

                
        }
    }
    else if(shape == 'T'){
        double length;
        double small_height,small_width;
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
            recb.set_dimensions_for_small_shape(small_width,small_height);
             composedSahpe com(myfile,tri_a,recb);
         }
    }
  
   myfile<<"</svg>";
   myfile.close();

    
    return 0;
} 