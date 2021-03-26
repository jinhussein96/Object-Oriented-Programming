
/**
* class Recangle
* @author JIN HUSSEIN
*/


public class Rectangle extends JPanel implements shape {
	private double  x ;
	private double y;
	private double width;
	private double height;
	private double area , perimeter;
	/**
    *   constructor with no param
    *   
    *
    */
	public Rectangle();
	/**
    *   constructor with param to set the coordinate and thd Dimensions
    *   @param double a,double b,double c, double d
    *
    */
	public Rectangle(double a, double b,double c, double d);
	public Rectangle(double a, double b);
	/**
    *   constructor with param of Rectangle
    *   @param other -to set the shape
    *
    */
	public Rectangle(Rectangle other);
	/**
    *   to set the shape
    *   @param a, b, c, d -  to set the coordinate and thd Dimensions
    *
    */
	public void  set_rec(double a, double b,double c, double d);
	/**
    *   to set the coordinate 
    *   @param a, b-  to set the coordinate 
    *
    */
	public void set(double a ,double b){
		x = a;
		y = b;
	}
	/**
    *   to get the x coordinate
    *   @return x coordinate
    *
    */
	
	public  double get_x(){
		return x;
	}
	/**
    *   to get the y coordinate
    *   @return y coordinate
    *
    */
	public  double  get_y(){
		return y;
	}
	/**
    *   to get the the width of the rectangle
    *   @return width
    *
    */
	public double get_width(){return width;}
	/**
    *   to get the the height of the rectangle
    *   @return hieght
    *
    */
	public double get_height(){return height;}
	/**
    *   to get the area of the rectangle
    *   @return area
    *
    */
	public double area(){

		return width*height;}
		/**
    *   to get the perimeter of the rectangle
    *   @return perimeter
    *
    */
	public double perimeter(){return 2*width +2*height;}
	public void post_increment(){
		this.set(y++,y++);
		
	}
	public void pre_increment(){
		this.set(++x,++y);
		
		
	}
	public void pre_decrement(){
		this.set(--x,--y);
		
	}
	public void post_decrement(){
		this.set(x--,x--);
				
	}

	public int compareTo(shape temp){
	 	return Double.valueOf(this.area()).compareTo(Double.valueOf(temp.area()));
	 }

	 public void draw(Graphics obj){
	 	int width = (int)get_width();
	 	int height = (int)get_height();
	 	int x = (int)get_x();
	 	int y = (int)get_y();
	 	obj.setColor(Color.white);
	 	obj.drawRect(x,y,width,height);
	 	obj.setColor(Color.RED);
	 	obj.fillRect(x,y,width,height);
	 }
	 public void paintComponent(Graphics obj){
	 	super.paintComponent(obj);
	 	draw(obj);
	 }
	 public String toString(){
		return String.format("%f,%f,%f,%f",width,height,x,y);
	}

}