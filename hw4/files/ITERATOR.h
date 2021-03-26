#ifndef ITERATOR_H_
#define ITERATOR_H_


#include <iostream>
using namespace std;


template<class E, template <class...> class ContainerT>  
class ITERATOR{

private:
	E* pointer;
public:
	ITERATOR(){pointer = new E;};
	ITERATOR(E* pointer1);
	~ITERATOR();
	ITERATOR(ContainerT<E,E>& p);
	ITERATOR(const ITERATOR& p);
	ITERATOR operator++(int) ;
	bool operator==(ITERATOR other) const; 

	bool operator!=(ITERATOR other) const ;
	int& operator*();
	
	bool hasNext();
	E& next();
	void remove();

};
#endif /*ITERATOR_H_ */ 