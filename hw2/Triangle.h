


#ifndef Triangle_H_
#define Triangle_H_

using namespace std;
class Triangle{
private:
    double length;
    double area;
    double point_a_x,point_a_y , point_b_x,point_b_y , point_c_x,point_c_y ;
    static double total_area;
    static double total_perimeter;
public:
    Triangle(): length(0),point_a_x(0),point_a_y(0), point_c_x(0),point_c_y(0),point_b_y(0),point_b_x(0) {};
    Triangle(double len):length(len){
        set_area();
        total_area += area;
        total_perimeter += (3*length);
    };
    Triangle(double A_x,double A_y ,double B_x,double B_y ,double C_x,double C_y):point_a_x(A_x),point_a_y(A_y),point_b_x(B_x),point_b_y(B_y),
    point_c_x(C_x),point_c_y(C_y)  {}
    void set_len(double len);
    void set_points(double point_A_x,double point_A_y ,double point_B_x,double point_B_y ,double point_C_x,double point_C_y);
    double get_len() const {return  length;};
    double get_point_a_x()const{return point_a_x;}
  
    double get_point_a_y()const{return point_a_y;}
    double get_point_b_x()const{return point_b_x;}
    double get_point_b_y()const{return point_b_y;}
    double get_point_c_x()const{return point_c_x;}
    double get_point_c_y()const{return point_c_y;}
    void draw(ofstream& file) const;
    void set_area(){area = (sqrt(3)/4)*pow(length,2);};
    const double get_area()const{return area;}
    const double get_perimeter()const{return 3*length;}
    Triangle operator++();
    Triangle operator++(int temp );
    Triangle operator--();
    Triangle operator--(int temp);
    const Triangle operator +(double number);
    const Triangle operator -(double number);
    friend const bool operator ==(const Triangle& tri1, const Triangle& tri2);
    friend const bool operator !=(const Triangle& tri1,const Triangle& tri2);
    friend ofstream& operator<<(ofstream& myfile,Triangle tri);

};

#endif /*Triangle_H_*/