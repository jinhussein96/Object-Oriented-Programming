
#ifndef triangle_H_
#define triangle_H_
#include <cmath>
#include <iostream>
#include "shape.h"

using namespace std;
namespace hw5{
class triangle:public shape{

	protected:
	double length;
	double X2,Y2;
	double X3,Y3;

	public:
		triangle():shape(){
			areaa = (sqrt(3)/4)*pow(length,2);
			
		};
		triangle(double lengths):length(lengths){areaa = (sqrt(3)/4)*pow(length,2);}
		triangle(double lengths , double x1 , double y1, double x2 , double y2, double x3 , double y3):
		shape(x1,y1),length(lengths),X2(x2),Y2(y2),X3(x3),Y3(y3) {areaa = (sqrt(3)/4)*pow(length,2);};
		const double get_length()const{return length;}
		void set_length(double a ){length = a;}
		const double get_x2()const{return X2;}
		const double get_y2()const{return Y2;}
		const double get_x3()const{return X3;}
		const double get_y3()const{return Y3;}
		void set_points(double x1 , double y1, double x2 , double y2, double x3 , double y3);
		void draw(ofstream& myfile)const;
		const double area()const{
			return  areaa; }
		const double perimeter()const{return 3*length;};
		virtual triangle& operator++();
		virtual triangle& operator++(int temp);
		virtual triangle& operator--();
		virtual triangle& operator--(int temp);
};
}
#endif /*triangle_H_ */ 