interface List<E> extends Collection<E>{
	public boolean equals(Object o);
	public int hashCode();
	public int indexOf(Object o);
	public Object toArray();
	
}