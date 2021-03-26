#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "Circle.h"
using namespace std;
double Circle::total_area_count = 0 ;
double Circle::total_perimeter_count = 0 ;
const Circle Circle::operator +(double number)const{
    auto temp1 = area + number;
    double temp=sqrt(temp1/3.14);
     
    return Circle(temp);
}
const Circle Circle::operator -(double number)const{
    auto temp1 = area - number;
    auto temp = sqrt(temp1/3.14);
    return Circle(temp);
}

Circle Circle::operator++(){
    cir_x++;
    cir_y++;
    return Circle(cir_x,cir_y);
}
Circle Circle::operator++(int temp){
    double temp1 = cir_x;
    double temp2 = cir_y;
    cir_x++;
    cir_y++;
    return Circle(temp1,temp2);
}
Circle Circle::operator--(){
    cir_x--;
    cir_y--;
    return Circle(cir_x,cir_y);
}
Circle Circle::operator--(int temp){
    double temp1 = cir_x;
    double temp2 = cir_y;
    cir_x--;
    cir_y--;
    return Circle(temp1,temp2);
}
const bool operator ==(const Circle& cir1,const Circle& cir2){
    return (cir1.get_area() == cir2.get_area());
} 
const bool operator !=(const Circle& cir1,const Circle& cir2){
    return (cir1.get_area() != cir2.get_area());
} 
void Circle::set_radius(double rds,double point_x,double point_y){
    radius = rds;
    cir_x = point_x;
    cir_y = point_y;
}

double Circle::get_radius()const{
    return radius;
}
ofstream& operator<<(ofstream& myfile,Circle cir){
    myfile <<"<circle cx = \""<<cir.cir_x<<"\" cy=\""<<cir.cir_y<<"\" r=\""<<cir.radius<<"\" fill= \"red\" stroke=\"black\" stroke-width=\"3\" />" ;
   myfile<<endl;
}