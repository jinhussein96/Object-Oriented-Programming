# include <vector>



#ifndef composedShape_H_
#define composedShape_H_
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

using namespace std;
enum  type {Rec ,Tri ,Cir};
class composedSahpe{
private:
    Rectangle reca , recb; //shape = 1
    Triangle tri_a,tri_b;//shape = 2
    Circle cir_a,cir_b;//shape = 3
    int main_shape,small_shape;

public:
    composedSahpe();
    composedSahpe(ofstream& file,Rectangle container_rec,Rectangle inner_rec);
    composedSahpe(ofstream& file,Rectangle container_rec , Circle inner_cir);
    composedSahpe(ofstream& file,Rectangle container_rec, Triangle inner_tri);
    composedSahpe(ofstream& file,Circle container_cir , Rectangle inner_rec);
    composedSahpe(ofstream& file,Circle container_cir , Triangle inner_tri);
    composedSahpe(ofstream& file,Circle container_cir,Circle inner_cir);
    composedSahpe(ofstream& file,Triangle container_tri , Triangle inner_tri);
    composedSahpe(ofstream& file,Triangle container_tri,Rectangle inner_rec);
    composedSahpe(ofstream& file,Triangle container_tri , Circle inner_cir);
    void set_shapes(int mainShape,int smallShape) ;
    void optimalFit(int main_shape,int small_shape);
    vector<Rectangle> rec_vector;
    vector<Circle> cir_vector;
    vector<Triangle> tri_vector;

    void draw_rec(ofstream& file);
    void draw_tri(ofstream& file);
    void draw_cir(ofstream& file);


    class shapeElem{
    private:
    	void *pointer;
    	type shape;
    public:
        shapeElem(Rectangle&);
        shapeElem(Circle&);
        shapeElem(Triangle&);
        double get_length()const;
        double get_radius()const;
        double get_rec_wdth()const;
        double get_rec_hght()const;
        
        double get_X_and_Y()const;
        
        const double get_area()const;
        const double get_perimeter()const;
        void set_shape(type temp_shape){
            
            shape = temp_shape;
        
        };
        const type get_shape_type(){
            return shape;
        };

    	friend ofstream& operator<<(ofstream& myfile,shapeElem& );

            
        };
         vector<shapeElem> lem_vec;
         composedSahpe& operator += (shapeElem& );
         friend ofstream& operator<<(ofstream& myfile , composedSahpe&);


    };

#endif /*composedShape_H_ */