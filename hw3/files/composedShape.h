#ifndef composedShape_H_
#define composedShape_H_

#include <iostream>
#include <vector>
#include "triangle.h"
#include "rectangle.h"
#include "circle.h"
#include "shape.h"


using namespace std;
using namespace hw5;
class composedShape: public shape{

private:
	 rectangle reca ;
     rectangle recb; //shape = 1
    triangle tri_a;
    triangle tri_b;//shape = 
    	circle cir_a;
        circle cir_b;//shape = 3
   

	vector<shape*> vec;
	int main_shape,inner_shape;
public:
	composedShape():shape(){};
	composedShape(rectangle& container_rec,rectangle& inner_rec);
    composedShape(rectangle& container_rec , circle& inner_cir);
    composedShape(rectangle& container_rec, triangle& inner_tri);
    composedShape(circle& container_cir , rectangle& inner_rec);
    composedShape(circle& container_cir , triangle& inner_tri);
    composedShape(circle& container_cir,circle& inner_cir);
    composedShape(triangle& container_tri , triangle& inner_tri);
    composedShape(triangle& container_tri,rectangle& inner_rec);
    composedShape(triangle& container_tri , circle& inner_cir);
    shape& operator[](const int index);
    const int get_vector_size()const{return vec.size();}
	const std::vector<shape*>& get_vector()const{return vec;};
    void optimalFit(int main_shape,int small_shape);
    virtual composedShape& operator++(){};
	virtual composedShape& operator--(){};
	virtual composedShape& operator++(int i){};
	virtual composedShape& operator--(int i){};
	const double area()const{};
	const double perimeter()const{};
    void draw(ofstream& file)const{};
        





};
#endif /*composedShape_H_ */ 