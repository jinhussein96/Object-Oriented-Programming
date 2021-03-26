
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>


#ifndef jin_
#define jin_

using namespace std;




enum class shapes{Rectangle , Circle  , Triangle };



void main_conatiner( int width , int height,int radius,int length,int small_shape_width,int small_shape_height,int small_shape_radius,int small_shape_length, enum  shapes main_shape,enum shapes small_shape);
void draw_small_circle(ofstream& file , int small_shape_radius,int main_shape_radius);
void draw_regtangle_inside_regtangle(ofstream& myfile,int width,int height,int small_shape_width,int small_shape_height);
void draw_circle_inside_rectangle(ofstream& file,int width ,int height , int radius);
void draw_triangle_inside_rectangle(ofstream& myfile,int rectangle_width,int rectangle_height,int triangle_length);
void draw_rectangle_inside_circle(ofstream& myfile , int circle_radius , int rectangle_width , int rectangle_height );
void draw_rectangle_inside_triangle(ofstream& myfile , int triangle_length,int rec_width,int rec_height);
void draw_triangle_inside_traingle(ofstream& myfile,int length,int small_shape_length);


#endif /*jin_*/