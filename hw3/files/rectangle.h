
#ifndef rectangle_H_
#define rectangle_H_
#include <iostream>
#include "shape.h"

using namespace std;
namespace hw5{

class rectangle:public shape{
private:
	double width , height;

public:
	rectangle():shape(){areaa =  width*height;};
	rectangle(double widthh, double heightt):width(widthh),height(heightt){areaa =  width*height;};
	rectangle(double widthh,double heightt,double X,double Y):shape(X,Y),width(widthh),height(heightt){areaa =  width*height;};
	void set_dimentions(double widthh,double heightt,double X,double Y);

	const double get_width()const{return width;}
	const double get_height()const{return height;}
	const double area()const{return areaa;};
	const double perimeter()const{return 2*width+2*height;}
	//friend ofstream& operator <<(ofstream& myfile,rectangle& rec);
	void draw(ofstream& myfile)const;
	virtual rectangle& operator++();
	virtual rectangle& operator--();	
	virtual rectangle& operator++(int temp);	
	virtual rectangle& operator--(int temp);
	
	
};
}
#endif /*rectangle_H_ */ 
