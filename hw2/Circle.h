

using namespace std;

#ifndef Circle_H_
#define Circle_H_


class Circle{
private:
    double radius;
    double cir_x,cir_y;
    double area;
    double perimeter;
    static double total_area_count;
    static double total_perimeter_count;
public:
    Circle(): radius(0),cir_x(0),cir_y(0),perimeter(0) {set_area(radius);};
    Circle(double rds) :radius(rds){
         set_area(radius);
         total_area_count += area;
         total_perimeter_count += (2*3.14*radius);
    };
    Circle(double x,double y):cir_x(x),cir_y(y){};
    Circle(double rds , double x , double y) :radius(rds),cir_x(x),cir_y(y){
        total_area_count += area;
        total_perimeter_count += (2*3.14*radius);
    };
    Circle operator++();
    Circle operator++(int temp );
    Circle operator--();
    Circle operator--(int temp);
    
    void set_radius(double rds){
        radius = rds;
        set_area(radius);
    };
    void set_radius(double rds,double point_x,double point_y);
    double get_radius() const;
    double get_point_x()const{return cir_x;}
    double get_point_y()const{return cir_y;}
    void set_area(double radius){

    area = 3.14*pow(radius,2);
    };
    const double get_area() const {
        
        return area;
    }
    const double get_perimeter()const{return 2 * 3.14 * radius;}
    const Circle operator+(double number)const;
    const Circle operator -(double number)const;
    friend ofstream& operator<<(ofstream& myfile , Circle cir);
    friend const bool operator ==(const Circle& cir1,const Circle& cir2);
    friend const bool operator !=(const Circle& cir1,const Circle& cir2);
    
    static double get_total_area(){
        return total_area_count;
    }
    static double get_total_perimtere(){
        return total_perimeter_count;
    }
    void draw(ofstream& file)const;
   

};
#endif /* Circle_H_ */ 