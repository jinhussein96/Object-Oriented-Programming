#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "triangle.h"
#include "shape.h"
using namespace std;
using namespace hw5;
 triangle&  triangle::operator++(){
			x++;
			y++;
			X2++;
			Y2++;
			X3++;
			Y3++;
			return *this;
}
triangle&  triangle::operator++(int temp){
			triangle& tri = *this;
			x++;y++;X2++;Y2++;X3++;Y3++;
			return tri;
}
triangle&  triangle::operator--(){
			x--;y--;X2--;Y2--;X3--;Y3--;
			return *this;
};
triangle&  triangle::operator--(int temp){
			triangle& tri = *this;
			x--;y--;X2--;Y2--;X3--;Y3--;
			return *this;
}

void  triangle::set_points(double x1 , double y1, double x2 , double y2, double x3 , double y3){
	x = x1;
	y = y1;
	X2 = x2;
	Y2 =y2;
	X3 = x3;
	Y3 = y3;
}

void triangle::draw(ofstream& myfile)const{
	 myfile<<"<path d=\"M"<<x<<" "<<y<<" L"<<X2<<" "<<Y2<<" L"<<X3<<" "<<Y3<<" Z \" stroke=\"green\" stroke-width=\"1\" fill=\"pink\" /> \n" ;
    myfile<<endl;
}
		