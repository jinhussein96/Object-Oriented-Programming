#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <cmath>
#include "arrayList.h"

template<class E, template <class...> class ContainerT>  
void arrayList<E,ContainerT>::addAll(collection<E,ContainerT>& c){
	
}
template<class E, template <class...> class ContainerT>  
bool arrayList<E,ContainerT>::contains(E e){
	for(int i = 0 ; i < c.size();i++){
		if(c[i] ==e)
			return true;
	}

	return false;
}
template<class E, template <class...> class ContainerT>  
void arrayList<E,ContainerT>::add(E e){
	c.push_back(e);
};

template<class E, template <class...> class ContainerT>  
void arrayList<E,ContainerT>::clear(){
	c.clear();
}

template<class E, template <class...> class ContainerT>  
int arrayList<E,ContainerT>::size(){

	return c.size();

}
template<class E, template <class...> class ContainerT>  
 E& arrayList<E,ContainerT>::iterator1(){
		/*!!!!!!!!*/
 }