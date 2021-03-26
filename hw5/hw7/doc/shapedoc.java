



/**
* interface shape
* @author JIN HUSSEIN
*/

interface shape extends Comparable<shape>{
	/**
    *   set shape's coordinate
    *   @param double - double coordinateX and coordinateY 
    *
    */
	public void set(double a , double b);
	/**
    *   return coordinateX 
    *   @return double -  return coordinateX
    *
    */
	public  double get_x();
	/**
    *   return coordinateY
    *   @return double -  return coordinateY
    *
    */
	public  double get_y();
	/**
    *   return shape area 
    *   @return double -  return area
    *
    */
	public double area();
	/**
    *   return shape perimeter 
    *   @return double -  return shape perimeter 
    *
    */
	public double perimeter();
	/**
    *   inccrementing shape postion by 1 
    *   
    *
    */
	public void post_increment();
	/**
    *   inccrementing shape postion by 1 
    *   
    *
    */
	public void pre_increment();
	/**
    *   decrementing shape postion by 1 
    *   
    *
    */
	public void post_decrement();
	/**
    *   decrementing shape postion by 1 
    *   
    *
    */
	public void pre_decrement();
	/**
    *    compares two shapes with respect to thier area 
    *   @param shape -shape to be compared with
    *	@return return 0 if the shapes are equal
    *
    */
	public int compareTo(shape temp);
	/**
    *   draws the shape 
    *   @param Graphics 
    *
    */
	public void draw(Graphics obj);
	/**
    *   Calls the UI delegate's paint method, if the UI delegate is non-null.
    *   @param obj - the Graphics object to protect 
    *
    */
	
	public void paintComponent(Graphics obj);
	

}