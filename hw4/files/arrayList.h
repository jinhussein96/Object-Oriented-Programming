#ifndef arrayList_H_
#define arrayList_H_
#include <iostream>
#include <vector>
#include <iterator>
#include "collection.h"
#include "LIST.h"
using namespace std;

template<class E, template <class...> class ContainerT>  
class arrayList:public LIST<E,ContainerT>{
private:
	 ContainerT<E> c;
public:
	arrayList(){}
	arrayList(ContainerT<E,E> temp){c = temp;};
	E& iterator1();
 	 bool contains(E e);
 	 void clear();
 	 void addAll(collection<E,ContainerT>& collectionn);
 	 void add(E e);
 	 bool isEmpty(){
 	 	return c.empty();
 	 };
 	 int size();

};


#endif /*arrayList_H_ */ 