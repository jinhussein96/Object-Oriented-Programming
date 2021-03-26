#ifndef circle_H_
#define circle_H_
#include <iostream>
#include "shape.h"
#define pi 3.14

using namespace std;
namespace hw5{
class circle : public shape{
protected:
	double radius;

	public:
		circle():shape(){};
		circle(double radiuss):radius(radiuss){
			areaa =pi* radius*radius;
		}
		circle(double radiuss , double x1 , double y1):
		shape(x1,y1) ,radius(radiuss){
			areaa =pi* radius*radius;
		};
		void set_radius(double a,double b,double c){
			radius = a;
			x = b;
			y = c;

		}
		const double get_radius()const{return radius;}
		const double area()const{
			return areaa; };
		const double perimeter()const{return 2*pi*radius;};
		//friend ofstream& operator <<(ofstream& myfile,circle& cir);
		void draw(ofstream& file)const;
		virtual circle& operator++();
		virtual circle& operator--();
		virtual circle& operator++(int temp);
		virtual circle& operator--(int temp);
};
}
#endif /*circle_H_ */ 
