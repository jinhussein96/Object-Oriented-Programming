#ifndef polygon_H_
#define polygon_H_
#include <cmath>
#include <iostream>
#include "shape.h"

using namespace std;

namespace hw5{

	class polygon:public shape{
		protected:
			int size;

		public:
			class _2Dpoints{
		private:
			double x , y;
		public:
			_2Dpoints(){};
			_2Dpoints(double a , double b){
				if(a >= 0.0 && b >= 0.0){
					x = a;
					y = b;
				}
				else {
					cout <<" there is something wrong with the given points \n";
					x = 0;
					y = 0;
				}
			};

			void set_x_y(double a,double b){
				if(a >= 0.0 && b >= 0.0){
						x = a;
						y = b;
					}
					else {
						cout <<" there is something wrong with the given points \n";
						x = 0;
						y = 0;
					}
			}
			const double get_x()const{
				return x;
			}
			const double get_y()const{
				return y;}

		};
			polygon():shape(){}
			const int get_size()const{return size;}
			virtual polygon& operator++(){};
			virtual polygon& operator--(){};
			virtual polygon& operator++(int i){};
			virtual polygon& operator--(int i){};
			const double area()const{};
			const double perimeter()const{};
		    void draw(ofstream& file)const{};
		    bool operator==(shape& shape1){};
		    bool operator!=(shape& shape1){};
		    



		   

	};




}
#endif /*polygon_H_ */ 