#include "ITERATOR.h"
template<class E, template <class...> class ContainerT>  
ITERATOR<E,ContainerT>::ITERATOR(E* pointer1){
		pointer = new E;
		*pointer = *pointer1;
}

template<class E, template <class...> class ContainerT>  
ITERATOR<E,ContainerT>::~ITERATOR(){
		delete[] pointer;
		pointer = NULL;
	}

template<class E, template <class...> class ContainerT>  
ITERATOR<E,ContainerT>::ITERATOR(ContainerT<E,E>& p){
		pointer = &*p;
		
}


template<class E, template <class...> class ContainerT>  
ITERATOR<E,ContainerT>::ITERATOR(const ITERATOR& p){
		pointer = new E;
		pointer = p.pointer;
}

template<class E, template <class...> class ContainerT>  
ITERATOR<E,ContainerT> ITERATOR<E,ContainerT>::operator++(int) {
			ITERATOR retval = *this;
			++(*this);
			return retval;
}
template<class E, template <class...> class ContainerT>  
bool ITERATOR<E,ContainerT>::operator==(ITERATOR other) const {
			return pointer == other.pointer;
		}
template<class E, template <class...> class ContainerT>  
bool ITERATOR<E,ContainerT>::operator!=(ITERATOR other) const {
			return !(*this == other);
		}
template<class E, template <class...> class ContainerT>  

int& ITERATOR<E,ContainerT>::operator*()
{return *pointer;}
template<class E, template <class...> class ContainerT>  
bool ITERATOR<E,ContainerT>::hasNext(){}
template<class E, template <class...> class ContainerT>  
E& ITERATOR<E,ContainerT>::next(){
		if(hasNext()){
			return ++pointer;
		}
};
template<class E, template <class...> class ContainerT>  
void ITERATOR<E,ContainerT>::remove(){
		for(auto *i = *pointer ; *i != NULL ; *i++){
			if((*i+1) == NULL)
				delete ++(i); 
		}
	};
