#ifndef polydyn_H_
#define polydyn_H_
#include <cmath>
#include <iostream>
#include "shape.h"
#include "polygon.h"
#include "triangle.h"
#include "rectangle.h"
#include "circle.h"
using namespace std;
namespace hw5{


class polydyn:public polygon{
private:
	double* x;
	double* y;
	double areaa;
	double perimeterr;
public:
	polydyn():polygon(){};
	~polydyn();
	polydyn(const polydyn& obj);
	polydyn(double a, double b,double area,double per):
	areaa(area),perimeterr(per){
		x = new double;
		*x = a;
		y = new double ;
		*y = b;
	}
	polydyn& operator=(const polydyn& poly);

	polydyn(rectangle& rec);
	polydyn(circle& cir);
	polydyn(triangle& tri);
	void draw(ofstream& file)const;
	bool operator==(shape& shape1){};
	bool operator!=(shape& shape1){};
	virtual polydyn& operator++();
	virtual polydyn& operator--();
	virtual polydyn& operator++(int i);
	virtual polydyn& operator--(int i);
	const double area()const{return areaa;};
	const double perimeter()const{return perimeterr;};
	
};

}
#endif /* polydyn_H_ */