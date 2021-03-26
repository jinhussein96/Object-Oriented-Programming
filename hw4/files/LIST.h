#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <vector>
#include <iterator>
#include "collection.h"
using namespace std;


template<class E, template <class...> class ContainerT>  
class LIST:public collection<E,ContainerT>{
public:
	virtual E& iterator1()=0;
 	virtual bool contains(E e)=0;
 	virtual void clear()=0;
 	virtual void addAll(collection<E,ContainerT>& c)=0;
 	virtual void add(E e)=0;
 	virtual bool isEmpty()=0;
 	virtual int size()=0;

};


#endif /*LIST_H_ */ 