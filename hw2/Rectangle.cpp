#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "Rectangle.h"
using namespace std;
double Rectangle::total_area = 0;
double Rectangle::total_perimeter=0;

Rectangle Rectangle::operator ++(){
    X++;
    Y++;
    return Rectangle(X,Y);
}
Rectangle Rectangle::operator ++(int temp){
    double temp1 = X;
    double temp2 = Y;
    X++;Y++;
    return Rectangle(temp1,temp2);

}
Rectangle Rectangle::operator --(){
    X--;
    Y--;
    return Rectangle(X,Y);
}
Rectangle Rectangle::operator --(int temp){
    double temp1 = X;
    double temp2=Y;
    X--;
    Y--;
    return Rectangle(temp1,temp2);
}
const Rectangle Rectangle::operator +(double number)const{
    auto temp = area +number;
    return Rectangle(temp/2,height,X,Y);
}
const Rectangle Rectangle::operator -(double number)const{
    auto temp = area - number;
    return Rectangle(temp/2,height,X,Y);
}
ofstream& operator <<(ofstream& myfile,Rectangle rec){
    char c = '"';

   myfile << "<rect x=\""<<rec.X<<"\" y=\""<<rec.Y<<"\" width= "<< c <<rec.width<< c << " height= " << c<<rec.height<< c<<endl ;
            
    myfile<< "style =\"fill:blue;stroke-width:0.5;stroke:black\" />"<<endl;  
}
void Rectangle::set_dimensions(double wdth,double hght,double x,double y){

    width = wdth;
    height = hght;
    X = x;
   Y = y;

}
void Rectangle::set_dimensions_for_small_shape(double small_width,double small_height){
    width = small_width;
    height = small_height;
}
double Rectangle::get_wdth() const{
    return width;
}
const bool operator==(const Rectangle& rec1,const Rectangle& rec2){
   return (rec1.get_area() == rec2.get_area());
}
const bool operator!=(const Rectangle& rec1,const Rectangle& rec2){
    return (rec1.get_area() != rec2.get_area());
}
    

double  Rectangle::get_hght() const {
    return height;

}

