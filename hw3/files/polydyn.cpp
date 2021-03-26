#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "polydyn.h"
using namespace std;
using namespace hw5;


polydyn::polydyn(rectangle& rec){
		x = new double[4];
		y = new double[4];
		areaa = rec.area();
		perimeterr = rec.perimeter();
		x[0] = rec.get_x();
		y[0] = rec.get_y();
		x[1] = rec.get_x()+rec.get_width();
		y[1] = rec.get_y();
		x[2] = rec.get_x()+rec.get_width();
		y[2] = rec.get_y()+rec.get_height();
		x[3] = rec.get_x();
		y[3] = rec.get_y()+rec.get_height();
		size = 4;
}
polydyn::polydyn(circle& cir){
		areaa = cir.area();
		perimeterr = cir.perimeter();
		x = new double [200];
		y = new double [200];
		size = 100;
		double i = 3.6;
		int j = 0;
		while(i <= 360){
			i +=3.6*j*(3.14/180);
			x[j] = cir.get_radius()*(cos(i))+cir.get_x();

			y[j] = cir.get_radius()*(sin(i))+cir.get_y();
			
			j++;
		}
}
polydyn::polydyn(triangle& tri){
	    areaa = tri.area();
		perimeterr = tri.perimeter();
		x = new double [3];
		y = new double [3];
		size = 3;
		x[0] = tri.get_x();
		y[0] =tri.get_y();
		x[1] = tri.get_x2();
		y[1] = tri.get_y2();
		x[2] =tri.get_x3();
		y[2] =tri.get_y3();
}
void polydyn::draw(ofstream& file)const{
	file<<"<polygon points=\"";
	for(int i = 0;i <size;i++){
		file<<x[i]<<","<<y[i];
		if(i == size-1)
			file<<"\"";
		else
			file<<" ";
	}
	file<<" style=\"fill:lime;stroke:purple;stroke-width:2;fill-rule:nonzero;\" />\n";


}
polydyn& polydyn::operator++(){
	for(int i = 0 ; i < size ; i++){
		x[i] = x[i]+1;
		y[i] = y[i]+1;
	}
	return *this;
};

polydyn& polydyn::operator++(int temp){
	polydyn& poly = *this;
	for(int i = 0 ; i < size ; i++){
			x[i] = x[i]+1;
			y[i] = y[i]+1;
		}
		return poly;

};
polydyn& polydyn::operator--(){
	for(int i = 0 ; i < size ; i++){
		x[i] = x[i]-1;
		y[i] = y[i]-1;
	}
	return *this;
};
polydyn& polydyn::operator--(int temp){
	polydyn& poly = *this;
	for(int i = 0 ; i < size ; i++){
			x[i] = x[i]-1;
			y[i] = y[i]-1;
		}
		return poly;
};
polydyn::~polydyn(){
	delete []x;
	delete []y;
	x = NULL;
	y = NULL;
}
polydyn::polydyn(const polydyn& obj){
	size = obj.get_size();
	x = new double[size];
	y = new double[size];
	copy(x,x+size,obj.x);
	copy(y,y+size,obj.y);
	
	areaa = obj.areaa;
	perimeterr = obj.perimeterr;

}

polydyn& polydyn::operator=(const polydyn& poly){
	double* newdata_x = new double[poly.get_size()];
	double* newdata_y = new double[poly.get_size()];
	copy(poly.x, poly.x+poly.get_size() , newdata_x);
	copy(poly.y, poly.y+poly.get_size() , newdata_y);
	delete[] x;
	delete[] y;
	x = newdata_x;
	y = newdata_y;
	areaa = poly.areaa;
	perimeterr = poly.perimeterr;
	size = poly.get_size();
	return *this;	
}



