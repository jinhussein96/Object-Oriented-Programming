/**
*	interface collection<E>
*	@author JIN HUSSEIN 
*/


interface Collection<E>{
	/**
	*	iterator over the collection 
	*	@return Returns an iterator over the elements in this collection.
	*/
	public ignore iterator();
	/**
	*	Ensures that this collection contains the specified element (optional operation).
	* 	@return true if this collection changed as a result of the call
	*/
	public boolean add(E e);
	/**
	*	Adds all of the elements in the specified collection to this collection (optional operation).
	*	@param c - c an object from Collection
	*	@return Adds all of the elements in the specified collection to this collection
	*/
	public void addAll(Collection c);
	/**
	*	Removes all of the elements from this collection
	*	
	*	@return removes all the elements
	*/
	public void clear();
	/**
	*	Returns true if this collection contains the specified element.
	*	@param E - E an object from the generic type
	*	@return true if this collection contains the specified element
	*/
	public boolean contains(E e);
	/**
	*	Returns true if this collection contains all of the elements in the specified collection.
	*	@param c - c an object from Collection
	*	@return true if this collection contains all of the elements in the specified collection
	*/
	public boolean containsAll(Collection c);
	/**
	*	Returns true if this collection contains no elements.
	*	@return true if this collection contains no elements
	*/
	public boolean isEmpty();
	/**
	*	Removes a single instance of the specified element from this collection, if it is present 
	*	@param E - E an object from the generic type
	*/
	public void remove(E e);
	/**
	*	Removes all of the elements from this collection
	*	@param c - c an object from Collection
	*	@return Adds all of the elements in the specified collection to this collection
	*/
	public void removeAll(Collection c);
	/**
	*	Retains only the elements in this collection that are contained in the specified collection
	*	@param elements - elements whose presence in this collection is to be ensured
	*/
	public void retainAll(Collection c);
	/**
	*	@return Returns the number of elements in this collection.
	*/
	public int size();
	/**
	*   fetching an element from the list\
	*	@param index 
	*	@return the value present at the specified index.
	*/
	public E get(int index);
	
}