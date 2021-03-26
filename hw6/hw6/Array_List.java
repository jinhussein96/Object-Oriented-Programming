@SuppressWarnings("unchecked")

public class Array_List<E> implements List<E>{
	private E[] arr;
	public Array_List(E[] temp){
		arr = (E[])temp;	
	}
	public Array_List(){
		arr = (E[]) new Object[0];
	}
	public ignore<E> iterator(){
		ignore<E> a = new ignore<E>(arr);
		return a;
	}
	public E get(int index){
		return arr[index];
	}	
 	public boolean contains(E e){
 		for(int i = 0 ; i < arr.length; i++){
 			if(arr[i] == e){
 				return true;
 			}
 		}
 		return false;
 	}
 	public E[] getarr(){return arr;}
	public int size(){return arr.length;}


	public int indexOf(Object o){
		for(int i = 0 ; i < arr.length; i++){
 			if(arr[i] == o){
 				return i;
 			}
 		}
 		return -1;
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
		else
			{E[] temp_arr =(E[]) new Object[arr.length-1];
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

        ignore it = c.iterator();
        while (it.hasNext()) {
        	remove((E)it.next());
            }
	}
	public boolean search(Object e){
		for(int i = 0 ; i < arr.length ; i++){
			if(arr[i] == e)
				return false;
		}
		return true;
	}
	public void clear(){
		arr = (E[]) new Object[arr.length];
		
	}





	public boolean add(E e){
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


	
	public int hashCode(){
		return (int)arr.hashCode(); 
	}
	
	
	public void addAll(Collection c){
		E[] temp_arr = (E[]) new Object[arr.length + c.size()];
		int j = 0;
		int k = 0;
		for(int i = 0 ; i < arr.length ; i++){
			temp_arr[j++] = arr[i];	
		}
		for(k = 0 ; k < c.size() ; k++){
			temp_arr[j++] = (E) c.get(k);
		}
		arr = (E[]) new Object[arr.length + c.size()];
		for(int i = 0 ; i < temp_arr.length;i++){
			arr[i] = temp_arr[i];
		}
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
	public Object[] toArray(){
		Object[] temp = new Object[arr.length];
		for(int i = 0 ; i < arr.length;i++){
			temp[i] =(Object)arr[i];
		}
		return temp;
	}

	
	public void retainAll(Collection c){
		boolean check ;
		for(int i = 0 ; i < size();i++){
			ignore<E> it = c.iterator();
			check = false;
			while(it.hasNext()){
				if(it.next() == arr[i]){
					check = true;
				}
			}
			if(!check){
				remove(arr[i]);
				i--;
			}
		}
	}
	
}
