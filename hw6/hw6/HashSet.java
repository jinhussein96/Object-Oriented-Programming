 public abstract  class HashSet<E> implements Set<E>{
	public abstract Object toArray();
	public abstract boolean add(E e);
	public abstract void addAll(Collection c);
	public abstract void clear();
	public abstract boolean contains(E e);
	public abstract boolean containsAll(Collection c);
	public abstract boolean isEmpty();
	public abstract void remove(E e);
	public abstract void removeAll(Collection c);
	public abstract void retainAll(Collection c);
	public abstract int size();
	public abstract E get(int index);

}


