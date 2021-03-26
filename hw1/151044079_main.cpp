#include <iostream>
#include "source1.h"

using namespace std;


int main(){
	char choise;
	shapes main_shape,small_shape ;
	cout << "Please enter the main container shape (R, C, T) "<< endl ;
	cin >> choise ;
	int temp = 0;
	while(temp != 1){

		if(choise == 'R'){
			main_shape = shapes::Rectangle;
			temp = 1;
		}
		else if(choise == 'C'){
			main_shape = shapes::Circle;
			temp = 1;
		}
		else if(choise == 'T'){
			main_shape = shapes::Triangle;
			temp = 1;
		}
		else {
			cout << "Please enter the main container shape (R, C, T)" << endl ;
			cin >> choise ;
		}
	}

	int width=0  , height=0;
	int radius=0;
	int length =0;
	if(main_shape == shapes::Rectangle)
		{
			cout << "Please enter the width" << endl ;
			cin >> width ;
			while(width <= 0){
				cout <<"width must be a positive number .... please enter the width again " << endl;
				cin >> width;
			}
			cout << "Please enter the height" << endl ;
			cin >> height ; 
			while(height <= 0){
				cout <<"height must be a positive number .... please enter the height again " << endl;
				cin >> height;
		}
	}
	else if(main_shape == shapes::Circle){
		cout << "please enter the radius " <<endl;
		cin >> radius ;
		while(radius <= 0){
			cout <<"radius can't be 0 or negative number .... please enter it again" <<endl;
			cin >> radius ;
		}

		
	}
	else if(main_shape == shapes::Triangle){
		cout << "please enter the length \n";
		cin >> length;
		while(length <= 0){
			cout << "length cant be a negative number....please enter the length again \n";
			cin >>length;
		}
	}

	char temp_small_shape;
	temp = 0;
	cout << "Please enter the small shape (R, C, T)" << endl ;
	cin >> temp_small_shape ;
	while(temp != 1){

		if(temp_small_shape == 'R'){
			small_shape = shapes::Rectangle;
			temp = 1;
		}
		else if(temp_small_shape == 'C'){
			small_shape = shapes::Circle;
			temp = 1;
		}
		else if(temp_small_shape == 'T'){
			small_shape = shapes::Triangle;
			temp = 1;
		}
		else {
			cout << "Please enter the small shape (R, C, T)" << endl ;
			cin >> temp_small_shape ;
		}
	}
	int small_shape_width , small_shape_height , small_shape_radius ;
	int small_shape_length;
	if(small_shape == shapes::Rectangle)
	{
		cout << "Please enter the width" << endl ;
		cin >> small_shape_width ;
		while(small_shape_width <= 0){
			cout <<"width must be a positive number .... please enter the width again " << endl;
			cin >> small_shape_width;
		}
		cout << "Please enter the height" << endl ;
		cin >> small_shape_height ; 
		
		while(small_shape_height <= 0 ){
			cout <<"height must be a positive number please enter the height again " << endl;
			cin >> small_shape_height;
		}
		
	}

	else if(small_shape == shapes::Circle){
			cout << "please enter the radius " <<endl;
			cin >> small_shape_radius ;
			while(small_shape_radius <= 0){
				cout <<"radius can't be 0 or negative number .... please enter it again" <<endl;
				cin >> small_shape_radius ;
			}

			
		}
	else if(small_shape == shapes::Triangle){
		cout <<"please enter the length"<<endl;
		cin >> small_shape_length;
		while(small_shape_length <= 0){
			cout<<"length cant be negative ... please enter a positive number\n";
			cin >> small_shape_length;		
		}	
	}


		main_conatiner (width,height,radius,length,small_shape_width,small_shape_height,small_shape_radius,small_shape_length,main_shape,small_shape);

		 


}