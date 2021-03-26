/**
* class triangle
* @author JIN HUSSEIN
*/

public class Triangle extends JPanel implements shape{
	private double x1 , y1, x2,y2,x3,y3;
	private double length;
	/**
    *   constructor with no param
    *   
    *
    */
    public Triangle();
    /**
    *   constructor with parameters to set the length and the coordinate
    *   @param a to set the length ,b to set the first point's x coordinate ,c to set the first point's y coordinate........
    *
    */
    public Triangle(double a,double b,double c,double d,double e,double f,double g);


	public void set(double a , double b);
	public  double get_x();
	public  double get_y();
	public  double get_x2();
	public  double get_y2();
	public  double get_x3();
	public  double get_y3();
	
	public double area();
	public double perimeter();
	public void post_increment();
	public void pre_increment();
	public void post_decrement();
	public void pre_decrement();
	public int compareTo(shape temp);
	public void draw(Graphics obj);
	public void paintComponent(Graphics obj);
	/**
    *   returns the side's length
    *	@return double -length   
    *
    */
	public double get_length(){return length;}
}