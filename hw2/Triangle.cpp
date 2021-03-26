#include <iostream>
#include <fstream>
#include <cmath>
#include "Triangle.h"

using namespace std;
double Triangle::total_area=0;
double Triangle::total_perimeter=0; 
    

Triangle Triangle::operator++(){
    point_a_x++;
    point_a_y++;
    point_b_x++;
    point_b_y++;
    point_c_x++;
    point_c_y++;
    return Triangle(point_a_x,point_a_y , point_b_x,point_b_y , point_c_x,point_c_y ) ;
}
Triangle Triangle::operator++(int temp){
    double temp1=point_a_x;
    double temp2=point_a_y;
    double temp3=point_b_x;
    double temp4=point_b_y;
    double temp5=point_c_x;
    double temp6=point_c_y;
    point_a_x++;
    point_a_y++;
    point_b_x++;
    point_b_y++;
    point_c_x++;
    point_c_y++;
    return Triangle(temp1,temp2,temp3,temp4,temp5,temp6) ;
}
Triangle Triangle::operator--(){
    point_a_x--;
    point_a_y--;
    point_b_x--;
    point_b_y--;
    point_c_x--;
    point_c_y--;
    return Triangle(point_a_x,point_a_y , point_b_x,point_b_y , point_c_x,point_c_y ) ;
}
Triangle Triangle::operator--(int temp){
    double temp1=point_a_x;
    double temp2=point_a_y;
    double temp3=point_b_x;
    double temp4=point_b_y;
    double temp5=point_c_x;
    double temp6=point_c_y;
    point_a_x--;
    point_a_y--;
    point_b_x--;
    point_b_y--;
    point_c_x--;
    point_c_y--;
    return Triangle(temp1,temp2,temp3,temp4,temp5,temp6) ;
}
ofstream& operator<<(ofstream& myfile,Triangle tri){

    myfile<<"<path d=\"M"<<tri.point_a_x<<" "<<tri.point_a_y<<" L"<<tri.point_b_x<<" "<<tri.point_b_y<<" L"<<tri.point_c_x <<" "<< tri.point_c_y<<" Z \" stroke=\"green\" stroke-width=\"1\" fill=\"pink\" /> \n" ;
    myfile<<endl;
}
void Triangle::set_points(double point_A_x,double point_A_y ,double point_B_x,double point_B_y ,double point_C_x,double point_C_y){
    point_a_x = point_A_x;
    point_a_y = point_A_y;
    point_b_x = point_B_x;
    point_b_y = point_B_y;
    point_c_x = point_C_x;
    point_c_y = point_C_y ; 




}

void Triangle::set_len(double len){
    length = len;
}

const bool operator ==(const Triangle& tri1,const Triangle& tri2){
    return(tri1.get_area() == tri2.get_area());
}
const bool operator !=(const Triangle& tri1, const Triangle& tri2){
    return(tri1.get_area() != tri2.get_area());
}

void Triangle::draw(ofstream& myfile)const{

    myfile<<"<path d=\"M"<<point_a_x<<" "<<point_a_y<<" L"<<point_b_x<<" "<<point_b_y<<" L"<<point_c_x <<" "<< point_c_y<<" Z \" stroke=\"green\" stroke-width=\"1\" fill=\"pink\" /> \n" ;
    myfile<<endl;
}
const Triangle Triangle::operator +(double number){
    auto temp_area = area + number;
    auto temp = sqrt(temp_area*4/(sqrt(3)));
    cout <<"temp   "<<temp<<endl;
    return Triangle(temp);
}