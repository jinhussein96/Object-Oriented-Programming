/**
* class Circle
* @author JIN HUSSEIN
*/



public class Circle extends JPanel implements shape{
	private double  x ;
	private double y;
	private double radius ;
	/**
    *   constructor with no param
    *   
    *
    */
	public Circle();
	/**
    *   constructor with parameter to set the radius and the coordinate
    *   @param r,a,b-double parameters to set radius and the coordinate
    *
    */
	public Circle(double r , double a , double b);
	public void set(double a , double b);
	public  double get_x();
	/**
    *   to get the radius of the circle
    *   @return the radius of the circle
    *
    */
	public double get_radius(){return radius;}
	public  double get_y();
	public double area();
	public double perimeter();
	public void pre_increment();
	public void post_increment();
	public void pre_decrement();
	public void post_decrement();
	public int compareTo(shape temp);
	public void draw(Graphics obj);
	public void paintComponent(Graphics obj);

}