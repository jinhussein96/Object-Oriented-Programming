

#ifndef shape_H_
#define shape_H_
#include <iostream>
using namespace std;
class shape{


protected :
	double x , y;
	double areaa;
public:
	shape(){};
	shape(double X , double Y);
	void set_dimention(double X , double Y);
	inline const double get_x()const{return x;}
	inline const double get_y()const{return y;}
	virtual const double area()const=0;
	virtual const double perimeter()const=0;
	virtual shape& operator++()=0;
	virtual shape& operator++(int temp)=0;
	virtual shape& operator--()=0;
	virtual shape& operator--(int temp)=0;
	virtual void draw(ofstream& file)const=0;
	virtual bool operator==(shape& shape1);
	virtual bool operator!=(shape& shape1);
	/*friend	ofstream& operator<<(ofstream& file ,shape& shape1){
		shape1.write(file);
		return file;
	}
*/
};

#endif /*shape_H_ */