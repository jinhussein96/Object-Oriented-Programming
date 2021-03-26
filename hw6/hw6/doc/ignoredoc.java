
/**
* class Iterator
* @author JIN HUSSEIN
*/
public class ignore<Type> {

    private Type[] array;
    private int currentSize;
    private int currentIndex;
    /**
    *   no param constructor
    *
    */
    public ignore(){}
    /**
    *   one param constructor 
    *   @param other - the array 
    *
    */
    public ignore(Type[] newArray);
    /**
    *   check if the next element is not null
    *   @return true if the iteration has more element 
    *
    */
    public boolean hasNext();
    /**
    *   return the next element in iteration 
    *   @return the next element in iteration
    *
    */
    public Type next() ;
    /**
    *   Removes from the underlying collection the last element returned by this iterator
    *
    */
    public void remove();
       
    
        
}

    