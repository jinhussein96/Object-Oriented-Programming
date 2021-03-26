#include "source1.h"







void main_conatiner( int width , int height,int radius,int length,int small_shape_width,int small_shape_height,int small_shape_radius,int small_shape_length, enum  shapes main_shape,enum shapes small_shape){

	ofstream myfile("output.svg");
	char c = '"';
	if(myfile.is_open()){
		if(main_shape == shapes::Rectangle){
			
			myfile <<" <svg width= " << c<< width <<c << " height= " << c << height << c << ">" <<endl ;
		  	myfile << "<rect width= "<< c << width << c << " height= " << c<< height << c << endl;
			myfile<< "style =\"fill:blue;stroke-width:2;stroke:green\" />"<<endl;
		  	if(small_shape == shapes::Circle){
				draw_circle_inside_rectangle(myfile,width ,height , small_shape_radius);
		  	}
		  	else if(small_shape == shapes::Rectangle){
			draw_regtangle_inside_regtangle(myfile,width,height,small_shape_width,small_shape_height);


		  	}
		  	else if(small_shape == shapes::Triangle){//its not done yet
				draw_triangle_inside_rectangle(myfile,width,height,small_shape_length);

		  	}

		     myfile << "</svg>" << endl;  			 
		}
		else if(main_shape == shapes::Circle){
			myfile <<"<svg> \n" ;
			myfile <<"<circle cx = \""<<radius<<"\" cy=\""<<radius<<"\" r=\""<<radius<<"\" fill= \"red\" />" ;
			if(small_shape == shapes::Circle){
				draw_small_circle(myfile,small_shape_radius,radius);
					
            
		  	}
			else if(small_shape == shapes::Rectangle){
				draw_rectangle_inside_circle(myfile ,radius , small_shape_width , small_shape_height );		
			}
			else if(small_shape == shapes::Triangle){
				//not done yet 
				

			}
			myfile <<"</svg>"<<endl ;

		}
		else if(main_shape == shapes::Triangle){
				myfile <<"<svg> \n";
				myfile<<"<path d=\"M"<<0<<" "<<(sqrt(3)/2)*length<<" L"<<length <<" "<<(sqrt(3)/2)*length<<" L"<<length/2 <<" "<< 0<<" Z \" stroke=\"green\" stroke-width=\"3\" fill=\"blue\" /> \n" ;
			if(small_shape == shapes::Rectangle){
				draw_rectangle_inside_triangle(myfile ,length, small_shape_width,small_shape_height);					
			}
			else if(small_shape == shapes::Triangle){
			draw_triangle_inside_traingle(myfile,length,small_shape_length);				
			
			}
				myfile <<"</svg>"<<endl ;
		
		}
		
        myfile.close(); 
       
	} 
	else cout << "unable to open file  \n"; 
}
void draw_small_circle(ofstream& file , int small_shape_radius,int main_shape_radius){
	int temp_num1 = main_shape_radius;
	int temp_num2 = main_shape_radius;
	int temp_num3 = main_shape_radius;
	int temp_num4 = main_shape_radius;
	int counter2 =0;
	int counter3 =0;
	int counter = 2*main_shape_radius / (small_shape_radius * 2);
	double main_shape_area =  3.14 *pow( main_shape_radius,2);
	double small_shape_area =  3.14 *pow( small_shape_radius,2);
while (temp_num3 > small_shape_radius){

	while(temp_num1 > small_shape_radius&& counter2 < counter ){
		counter3++;
		main_shape_area -= small_shape_area;
		file <<endl <<"<circle cx = \""<<temp_num1<<"\" cy=\""<<temp_num3<<"\" r=\""<<small_shape_radius<<"\" fill= \"green\" />" <<endl;
		file <<endl <<"<circle cx = \""<<temp_num2<<"\" cy=\""<<temp_num3<<"\" r=\""<<small_shape_radius<<"\" fill= \"green\" />" <<endl;
		temp_num1 -= 2*small_shape_radius;
		temp_num2 += 2*small_shape_radius;
		counter2++;
	}
	counter -= 2;
	counter2 = 0;
	temp_num1 = main_shape_radius;
	temp_num2 = main_shape_radius;
	temp_num3 -= 2*small_shape_radius;
}
 temp_num1 = main_shape_radius;
 temp_num2 = main_shape_radius;
	 temp_num3 = main_shape_radius;
	 temp_num4 = main_shape_radius;
	counter =2* main_shape_radius / (small_shape_radius * 2);
	 counter2=0;
while (temp_num3 < 2*main_shape_radius - small_shape_radius){

	while(temp_num1 > small_shape_radius && counter2 < counter ){
		counter3++;
		main_shape_area -= small_shape_area;
		file <<endl <<"<circle cx = \""<<temp_num1<<"\" cy=\""<<temp_num3<<"\" r=\""<<small_shape_radius<<"\" fill= \"green\" />" <<endl;
		file <<endl <<"<circle cx = \""<<temp_num2<<"\" cy=\""<<temp_num3<<"\" r=\""<<small_shape_radius<<"\" fill= \"green\" />" <<endl;
		temp_num1 -= 2*small_shape_radius;
		temp_num2 += 2*small_shape_radius;
		counter2++;
		
		}
	counter -= 2;
	counter2 = 0;
	temp_num1 = main_shape_radius;
	temp_num2 = main_shape_radius;
	temp_num3 += 2*small_shape_radius;

	}
cout << "i can fit "<<counter3<<" small shapes into the main shape and the empty area is "<<main_shape_area<<endl;;	
}

void draw_regtangle_inside_regtangle(ofstream& myfile,int width,int height,int small_shape_width,int small_shape_height){
	int temp_width = small_shape_width;
	int temp_height = small_shape_height; ;
	int counter = 0;
	int big_area = width*height;
	int small_area = small_shape_width * small_shape_height;
	

	char c = '"';
	while(temp_height < height){
		while(temp_width < width){
			myfile << "<rect x=\""<<temp_width<<"\" y=\""<<temp_height<<"\" width= "<< c << small_shape_width<< c << " height= " << c<< small_shape_height<< c<<endl ;
			
			myfile<< "style =\"fill:red;stroke-width:2;stroke:black\" />"<<endl;			
			temp_width += small_shape_width;
			counter++;
			big_area -= small_area;
		}
		temp_width = small_shape_width;
		temp_height +=small_shape_height;

	}
	cout << "i could fit " << counter<<" rectangles in the big rectangle and the area is "<<big_area<<endl;
}

void draw_circle_inside_rectangle(ofstream& myfile,int width ,int height , int radius){
      int temp_height = radius ;
      int temp_width = radius ;
	int circle_area = 3.14 * pow(radius,2);
	int rectangle_area = width * height;
	int small_circles_counter = 0;
	while(temp_height <= height-radius){
		while(temp_width <=width-radius ){
			myfile <<"<circle cx = \""<<temp_width<<"\" cy=\""<<temp_height<<"\" r=\""<<radius<<"\"" ;
			myfile<< " style =\"fill:green;stroke-width:2;stroke:black\" />"<<endl;
			temp_width += 2*radius;
			rectangle_area -= circle_area;
			small_circles_counter++; 
		}

		temp_width = radius;
		temp_height += 2*radius;
	}
	cout<<"i could fit " <<small_circles_counter<<" inside the rectangle and the area is "<<rectangle_area <<endl;
	
}
void draw_triangle_inside_rectangle(ofstream& myfile,int rectangle_width,int rectangle_height,int triangle_length){
	int point_x=0;
	
	int  point_y = pow(triangle_length,2) - pow((triangle_length/2),2);
	point_y = sqrt(point_y);
	int y = point_y;
	int point3_x = triangle_length/2;
	int point3_y=0;
	int triangle_counter = 0;
	int area = rectangle_width * rectangle_height;
	int triangle_area = point_y * (triangle_length/2);
	while(point_y <= rectangle_height){
		while(point_x <= rectangle_width - triangle_length/2){
			myfile<<"<path d=\"M"<<point_x<<" "<<point_y<<" L"<<point_x+triangle_length <<" "<< point_y<<" L"<<point3_x <<" "<< point3_y <<" Z \" /> \n" ;
			triangle_counter++;
			if(point3_x+triangle_length < rectangle_width){
				myfile<<"<path d=\"M"<<point3_x<<" "<<point3_y<<" L"<<point_x+triangle_length <<" "<<
				 point_y<<" L"<<point3_x+triangle_length <<" "<< point3_y <<" Z \" /> \n" ;
				triangle_counter++;
				area -= triangle_area;			
			}
			point_x += triangle_length;
			point3_x += triangle_length;
			area -= triangle_area;
		
		}
		point_x = 0;
		point3_x = triangle_length/2;
		point3_y += y;
		point_y += y;
	}
	cout <<"i can fit "<<triangle_counter<<" at most into the rectangle and the empty area is "<<area<<endl;
	
}



void draw_rectangle_inside_circle(ofstream& myfile , int circle_radius , int rectangle_width , int rectangle_height ){
	//<rect x="50" y="20" width="150" height="150"
	//style ="fill:blue;stroke-width:2;stroke:green" />
	int point1_x=circle_radius-rectangle_width/2;
	int point1_y=circle_radius-rectangle_height/2;
	int point2_x=circle_radius-rectangle_width/2;
	int point2_y=circle_radius-rectangle_height/2;
	int temp = (2*circle_radius) / rectangle_width;
	int temp2 = 0;
	int circle_counter =0;
	double circle_area = 3.14 * pow(circle_radius,2);
	double rectangle_area = rectangle_width * rectangle_height;
	while(point1_y >= 0 && point2_y <= 2*circle_radius){
	while(point1_x >= 0 && point2_x <= 2*circle_radius &&temp2 < temp){
		myfile<<"\n<rect x=\""<<point1_x<<"\" y=\""<<point1_y<<"\" width=\""<<rectangle_width<<"\" height=\""<<rectangle_height<<"\"" ;
		myfile<< " style =\"fill:blue;stroke-width:2;stroke:green\" />"<<endl;
		myfile<<"\n<rect x=\""<<point2_x<<"\" y=\""<<point2_y<<"\" width=\""<<rectangle_width<<"\" height=\""<<rectangle_height<<"\"" ;
		myfile<< " style =\"fill:blue;stroke-width:2;stroke:green\" />"<<endl;
		myfile<<"\n<rect x=\""<<point1_x<<"\" y=\""<<point2_y<<"\" width=\""<<rectangle_width<<"\" height=\""<<rectangle_height<<"\"" ;
		myfile<< " style =\"fill:blue;stroke-width:2;stroke:green\" />"<<endl;
		myfile<<"\n<rect x=\""<<point2_x<<"\" y=\""<<point1_y<<"\" width=\""<<rectangle_width<<"\" height=\""<<rectangle_height<<"\"" ;
		myfile<< " style =\"fill:blue;stroke-width:2;stroke:green\" />"<<endl;
			temp2++;
		point1_x -= rectangle_width;
		point2_x += rectangle_width;
		circle_area -= rectangle_area;
		circle_counter++ ;	
	}
	
	temp -= 2;
	temp2 = 0;

	point1_x=circle_radius-rectangle_width/2;
	point2_x=circle_radius-rectangle_width/2;
	point1_y -= rectangle_height;
	point2_y += rectangle_height;

			  	
}
	cout <<"i can fit at most "<<circle_counter<<" small shapes into the main container . the empty area is "<<circle_area <<endl;


}


void draw_rectangle_inside_triangle(ofstream& myfile , int triangle_length,int rec_width,int rec_height){
		
		
		int triangle_height = pow(triangle_length,2)-pow(triangle_length/2,2);
		triangle_height=sqrt(triangle_height);
		int point1_x = (1/sqrt(3))*rec_height;
		int temp_point_x=point1_x;
		int point1_y = triangle_height-rec_height;
		int counter = triangle_length / rec_height;
		int counter2 = 0;
		int counter3 =1;
		int temp_triangle_length = triangle_length;
		double rec_area = rec_width * rec_height;
		double tri_area = pow(triangle_length,2)*sqrt(3)/4;
	while(point1_y >= 0){
		while(point1_x+rec_width < temp_triangle_length){
		myfile<<"\n<rect x=\""<<point1_x<<"\" y=\""<<point1_y<<"\" width=\""<<rec_width<<"\" height=\""<<rec_height<<"\"" ;
		myfile<< " style =\"fill:red;stroke-width:1;stroke:green\" />"<<endl;
		point1_x += rec_width;
		counter2++;
	tri_area -= rec_area;
		}
	counter3++;
	point1_x = (1/sqrt(3))*rec_height/2;
	point1_x += counter3*temp_point_x;
	
	point1_y -= rec_height;
	temp_triangle_length -= rec_height/2;
	counter = temp_triangle_length/rec_width;
	}

	cout <<"i can fit at most "<<counter2<<" small shapes into the main container . the empty area is "<<tri_area <<endl;




}


void draw_triangle_inside_traingle(ofstream& myfile,int length,int small_shape_length){


	int main_shape_height = sqrt(pow(length,2)-pow(length/2,2));
	int small_shape_height = sqrt(pow(small_shape_length,2)-pow(small_shape_length/2,2));
	double main_shape_area = sqrt(3)/4 * pow(length,2);
	double small_shape_area = sqrt(3) / 4 * pow(small_shape_length,2);
	cout << main_shape_area <<endl;
	cout << small_shape_area <<endl;
	
	int point1_x =0;
	int point1_y=main_shape_height;
	int point2_x = small_shape_length/2;
	int point2_y= main_shape_height - small_shape_height;
	int point3_x =point1_x + small_shape_length ;
	int point3_y = point1_y;
	int temp_main_length = length;
	int counter =0;
	int triangle_counter = 0;
	while(point2_y >= 0){ 
		while(point3_x <= temp_main_length){
		triangle_counter++;
		main_shape_area -= small_shape_area;
		myfile<<"<path d=\"M"<<point1_x<<" "<<point1_y<<" L"<<point2_x <<" "<< point2_y<<" L"<<point3_x <<" "<< point3_y <<" Z \" stroke=\"green\" stroke-width=\"3\" fill=\"blue\"  /> \n" ;
		if(point3_x+small_shape_length <= temp_main_length){
			main_shape_area -= small_shape_area;
			triangle_counter++;
			
			myfile<<"<path d=\"M"<<point3_x<<" "<<point3_y<<" L"<<point2_x <<" "<< point2_y<<" L"<<point2_x+small_shape_length <<" "<< point2_y <<" Z  \" stroke=\"green\" stroke-width=\"3\" fill=\"blue\" /> \n" ;
	
		}
		point1_x += small_shape_length;
		point3_x += small_shape_length;
		point2_x += small_shape_length;
		}
counter++;
		point1_x = counter*(small_shape_length/2);
		point2_x = counter*(small_shape_length/2)+small_shape_length/2;
		point3_x = counter*(small_shape_length/2) + small_shape_length;
		
		temp_main_length -= small_shape_length/2;
		point1_y -= small_shape_height;
		point3_y = point1_y;
		point2_y -= small_shape_height;		
		
		
	}
	cout<<"i can fit at most "<<triangle_counter<<" small shapes into the main shape .the empty area in container is "<<main_shape_area<<endl;
}










