#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "polyvec.h"
using namespace std;
using namespace hw5;


polyvec::polyvec(rectangle& rec){
	areaa = rec.area();
	perimetera = rec.perimeter();

	_2Dpoints* point = new _2Dpoints(rec.get_x(),rec.get_y());
	add_to_vec(point);
	_2Dpoints* point2 = new _2Dpoints(rec.get_x()+rec.get_width(),rec.get_y());
	add_to_vec(point2);

	_2Dpoints* point3 = new _2Dpoints(rec.get_x()+rec.get_width(),rec.get_y()+rec.get_height());
	add_to_vec(point3);

	_2Dpoints* point4 = new _2Dpoints(rec.get_x(),rec.get_y()+rec.get_height());
	add_to_vec(point4);
	size = 4;
}
polyvec::polyvec(circle& cir){
	areaa = cir.area();
	perimetera = cir.perimeter();
	size = 100;
	double i = 3.6;
	int j = 0;

	_2Dpoints* point = new _2Dpoints;
	while(i <= 360){
		i +=3.6*j*(3.14/180);
		point = new _2Dpoints(cir.get_radius()*(cos(i))+cir.get_x(),cir.get_radius()*(sin(i))+cir.get_y());
		j++;
		add_to_vec(point);
	
	}
}
polyvec::polyvec(triangle& tri){
	size = 3;
	areaa = tri.area();
	perimetera = tri.perimeter();
	_2Dpoints* point = new _2Dpoints(tri.get_x(),tri.get_y());
	add_to_vec(point);
	_2Dpoints* point2 = new _2Dpoints(tri.get_x2(),tri.get_y2());
	add_to_vec(point2);

	_2Dpoints* point3 = new _2Dpoints(tri.get_x3(),tri.get_y3());
	add_to_vec(point3);
}


void polyvec::add_to_vec(_2Dpoints* point){
	v.push_back(point);
}
void polyvec::draw(ofstream& file)const{
	file<<"<polygon points=\"";
	for(int i = 0;i < v.size();i++){
		file<<v[i]->get_x()<<","<<v[i]->get_y();
		if(i == v.size()-1)
			file<<"\"";
		else
			file<<" ";
	}
	file<<" style=\"fill:lime;stroke:purple;stroke-width:2;fill-rule:nonzero;\" />\n";

}
polyvec& polyvec::operator++(){
	for(int i = 0 ; i < size ; i++){
	v[i]->set_x_y(v[i]->get_x()+1,v[i]->get_y()+1);}
	return *this;
};
polyvec& polyvec::operator++(int temp){
	polyvec &poly = *this;
	for(int i = 0 ; i < size ; i++){
	v[i]->set_x_y(v[i]->get_x()+1,v[i]->get_y()+1);}
	return poly;
};
polyvec& polyvec::operator--(){
	for(int i = 0 ; i < size ; i++){
	v[i]->set_x_y(v[i]->get_x()-1,v[i]->get_y()-1);}
	return *this;

};
polyvec& polyvec::operator--(int temp){
	polyvec &poly = *this;
	for(int i = 0 ; i < size ; i++){
	v[i]->set_x_y(v[i]->get_x()-1,v[i]->get_y()-1);}
	return poly;
};
/*polyvec& polyvec::convert(shape& shape){
	polyvec pol;

}*/