@SuppressWarnings("unchecked")

public class TreeSet<E> extends HashSet<E> implements Set<E>{
	private E[] arr;

	public TreeSet(){
		arr = (E[]) new Object[0];
	}

	public TreeSet(E[] temp){
		arr = (E[])temp;	
	}
	public boolean add(E e){
		if(this.contains(e)){
			return false;
		}
		else{
				E[] temp_arr = (E[]) new Object[arr.length+1];
					for(int i = 0 ; i < arr.length ;i++){
						temp_arr[i] = arr[i];
					}
					temp_arr[arr.length] = e;
				 arr = (E[]) new Object[temp_arr.length];
				 for(int i = 0 ; i < arr.length ;i++){
						arr[i] = temp_arr[i];
					}
				 return true;
			}
	}
	public void addAll(Collection c){
		for(int i =0; i < c.size();i++){
			add((E)c.get(i));
		}
	}
	public void clear(){
		arr = (E[]) new Object[0];
	}
	public boolean contains(E e){
		for(int i = 0 ; i < arr.length; i++){
 			if(arr[i] == e){
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
	public boolean isEmpty(){
		if(arr.length <= 0){
			return true;
		}
		return false;
	}
	public void remove(E e){
		if(!contains(e)){
			System.out.println("the element is not found");
		}
		else{E[] temp_arr =(E[]) new Object[arr.length-1];
				int j = 0;
				for(int i = 0 ; i < arr.length ; i++){
					if(arr[i]!= e){
						temp_arr[j++] = arr[i];
					}
				}
				arr = (E[]) new Object[temp_arr.length];
				for(int i = 0 ; i < temp_arr.length ; i++){
					arr[i] = temp_arr[i];
				}}
	}
	public void removeAll(Collection c){
		ignore it = iterator();
		int i =0;
        while (it.hasNext()&& i < arr.length) {
            if (c.contains(it.next())) {
              	 remove(arr[i]);
                
            }
            i++;
        }
        
	}
	public void retainAll(Collection c){}
	public int size(){return arr.length;}
	public E get(int index){return arr[index];}

	
	public ignore iterator(){
		ignore<E> a = new ignore<E>(arr);
		return a;
	}
	
	public Object[] toArray(){
		Object[] temp = new Object[arr.length];
		for(int i = 0 ; i < arr.length;i++){
			temp[i] =(Object)arr[i];
		}
		return temp;
	}
		



}


