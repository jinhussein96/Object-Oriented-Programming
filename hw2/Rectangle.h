

#ifndef Rectangle_H_
#define Rectangle_H_

using namespace std;

class Rectangle{
private:
    double width,height;
    double X , Y;
    double area;
    double perimter;
    static double total_area;
    static double total_perimeter;

public:

    Rectangle():width(0) , height(0),X(0),Y(0) {};
    Rectangle(double w,double h, double x,double y ):width(w) , height(h),X(x),Y(y) {
        set_area();
        total_area += area;
        total_perimeter += (2*width + 2*height);
    };
    Rectangle(double x, double y):X(x),Y(y){};
    void set_dimensions(double wdth,double hght,double x,double y);
    void set_dimensions_for_small_shape(double small_width,double small_height);
    double get_wdth() const ;
    double get_hght() const ;
    double get_rec_x()const {return X;}
    double get_rec_y()const{return Y;}
    static double get_total_area(){return total_area;}
    static double get_total_perimeter(){
        return total_perimeter;
    }
    void draw(ofstream& file)const;
    void set_area(){area = width*height;};
    const double get_area()const{return area;}
    const double get_perimeter()const{return (2*width +2*height);}
    Rectangle operator ++();
    Rectangle operator ++(int temp );
    Rectangle operator --();
    Rectangle operator --(int temp);
    const Rectangle operator +(double number)const;
    const Rectangle operator -(double number)const;
    friend const  bool operator ==(const Rectangle& rec1,const Rectangle& rec2);
    friend const  bool operator !=(const Rectangle& rec1,const Rectangle& rec2);
    friend ofstream& operator<<(ofstream& myfile,Rectangle rec);
    

};
#endif /* Rectangle_H_ */