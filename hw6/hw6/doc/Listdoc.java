

/**
* interface List<E>
* @author JIN HUSSEIN
*/


interface List<E> extends Collection<E>{

	/**
	*	Compares the specified object with this set for equality.
	*	@param o - object to be compared for equality with this set
	*	@return   true if the specified object is equal to this list
	*/
	public boolean equals(Object o);
	
	/**
	*	Returns the hash code value for this list.
	*
	*	@return   Returns the hash code value for this list.
	*/
	public int hashCode();
	/**
	*	Returns the index of the first occurrence of the specified element in this list, or -1 if this list does not contain the element.
	*	@param o - element to search for
	*	@return   Returns the index of the first occurrence of the specified element in this list, or -1 if this list does not contain the element..
	*/
	public int indexOf(Object o);
	/**
	*	Returns an array containing all of the elements in this list in proper sequence (from first to last element).
	*	@return   Returns an array containing all of the elements in this list in proper sequence (from first to last element).
	*/
	public Object toArray();
	
}