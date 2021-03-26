#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "rectangle.h"
#include "shape.h"
using namespace std;
namespace hw5{

rectangle& rectangle::operator++(){
	x++;
	y++;
		return *this;
}
rectangle& rectangle::operator--(){
		x--;y--;
		return *this;
	}
rectangle& rectangle::operator++(int temp){
		rectangle& rec = *this;
		x++;
		y++;
		return rec;
}
rectangle& rectangle::operator--(int temp){
		rectangle& rec = *this;
		x--;
		y--;
		return rec;
}
	
void rectangle::set_dimentions(double widthh,double heightt,double X,double Y){
	x = X;
	y = Y;
	width = widthh;
	height = heightt;
}
/*void rectangle::write(ofstream& myfile){
	
	//shape::write(myfile);
	 char c = '"';

   myfile << "<rect x=\""<<x<<"\" y=\""<<y<<"\" width= "<< c <<width<< c << " height= " << c<<height<< c<<endl ;
            
    myfile<< "style =\"fill:blue;stroke-width:0.5;stroke:black\" />"<<endl;  

}*/
void rectangle::draw(ofstream& myfile)const{
    char c = '"';

   myfile << "<rect x=\""<<x<<"\" y=\""<<y<<"\" width= "<< c <<width<< c << " height= " << c<<height<< c<<endl ;
            
    myfile<< "style =\"fill:blue;stroke-width:0.5;stroke:black\" />"<<endl;  
}
}