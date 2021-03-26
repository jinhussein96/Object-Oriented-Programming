#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "circle.h"
#include "shape.h"
using namespace std;
using namespace hw5;

 circle& circle::operator++(){
			x++;
			y++;
			return *this;
};
circle& circle::operator--(){
		x--;y--;
		return *this;
}
circle& circle::operator++(int temp){
		circle& cir = *this;
		x++;
		y++;
		return cir;
}
circle& circle::operator--(int temp){
		circle& cir = *this;
		x--;
		y--;
		return cir;
}
void circle::draw(ofstream& file)const{

   file <<"<circle cx = \""<<x<<"\" cy=\""<<y<<"\" r=\""<<radius<<"\" fill= \"red\" stroke=\"black\" stroke-width=\"3\" />" ;
   file<<endl;

}