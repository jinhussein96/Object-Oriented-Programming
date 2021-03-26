@SuppressWarnings("unchecked")

public class LinkedList<E> implements Queue<E> , List<E>{
	private E[] array;
	private int capacity,size;

	public LinkedList(){
		size = 0 ;
		capacity =1;
		array = (E[]) new Object[capacity];
	}
	public ignore iterator(){
		ignore<E> a = new ignore<E>(array);
		return a;
	}
	
	public boolean add(E e){
		if(size < capacity){
			array[size] = e;
			size++;
			return true;
		}
		return false;
	}
	public void addAll(Collection c){
		for(int i =0; i < c.size();i++){
			add((E)c.get(i));
		}
	}
	public void clear(){
		 array = (E[])new Object[capacity];
        size = 0;
	}
	public boolean contains(E e){
		for(int i = 0 ; i < array.length; i++){
 			if(array[i] == e){
 				return true;
 			}
 		}
 		return false;
	}
	public boolean containsAll(Collection c){
		E[] a = (E[])new Object[c.size()];
		 for(int i = 0 ; i < a.length;i++){
		 	a[i] = (E)c.get(i);
		 }
		for(E e : a){
			if(!contains(e)){
				return false;
			}
		}
		return true;
	}
	public boolean isEmpty(){return size == 0;}
	public void remove(E e){
		if(!contains(e)){
			System.out.println("the element is not found");
		}
		else{
		     E[] temp_arr =(E[]) new Object[array.length-1];
		int j = 0;
		for(int i = 0 ; i < array.length ; i++){
			if(array[i]!= e){
				temp_arr[j++] = array[i];
			}
		}
		array = (E[]) new Object[temp_arr.length];
		for(int i = 0 ; i < temp_arr.length ; i++){
			array[i] = temp_arr[i];
		}   
	}
	}
	public void removeAll(Collection c){
		ignore it = c.iterator();
        while (it.hasNext()) {
        	remove((E)it.next());
            }
	}
	public void retainAll(Collection c){
		boolean check ;
		for(int i = 0 ; i < size();i++){
			ignore<E> it = c.iterator();
			check = false;
			while(it.hasNext()){
				if(it.next() == array[i]){
					check = true;
				}
			}
			if(!check){
				remove(array[i]);
				i--;
			}
		}
	}
	public int size(){return size;}
	public E get(int index){return array[index];}
	public boolean offer(E e){
		if(size < capacity){
			add(e);
			return true;
		}
		return false;
	}
	public E poll(){
		if(!isEmpty()){
			E e = array[0];
			remove(array[0]);
			return e;
		}
		return null;
	}
	public Object toArray(){
		Object[] temp = new Object[array.length];
		for(int i = 0 ; i < array.length;i++){
			temp[i] =(Object)array[i];
		}
		return temp;
	}
	public int indexOf(Object o){
		for(int i = 0 ; i < array.length;i++){
			if(array[i] == o){ 
				return i;
			}
		}
		return -1;
	}

}
