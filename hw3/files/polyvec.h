#ifndef polyvec_H_
#define polyvec_H_
#include <cmath>
#include <iostream>
#include "shape.h"
#include "polygon.h"
#include "triangle.h"
#include "rectangle.h"
#include "circle.h"
using namespace std;
namespace hw5{

class polyvec:public polygon{
public:
	polyvec():polygon(){}
	polyvec(vector<polygon::_2Dpoints*>& vec){v = vec;}
	polyvec(rectangle& rec);
	polyvec(circle& cir);
	polyvec(triangle& tri);
	const vector<polygon::_2Dpoints*>& get_vector()const{return v;}
	void add_to_vec(_2Dpoints* point);
	void draw(ofstream& file)const;
	bool operator==(shape& shape1){};
	bool operator!=(shape& shape1){};
	virtual polyvec& operator++();
	virtual polyvec& operator++(int temp);
	virtual polyvec& operator--();
	virtual polyvec& operator--(int temp);
	const double area()const{return areaa;};
	const double perimeter()const{return perimetera;};
	ofstream& operator<<(ofstream& myfile){
		this->draw(myfile);
		return myfile;

	}
private:
	std::vector<polygon::_2Dpoints*> v;
	double areaa;
	double perimetera;

};



}

#endif /* polyvec_H_ */