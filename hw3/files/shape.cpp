
#include "shape.h"
using namespace std;


shape::shape(double X,double Y){
	x=X;
	y=Y;
};
void shape::set_dimention(double X,double Y){
	x = X;
	y = Y;
}

bool shape::operator==(shape& shape1){
		return this->area()==shape1.area();
}
bool shape::operator!=(shape& shape1){
		return this->area()!=shape1.area();
}

///////////////global functions ////////////////////////
