#ifndef collection_H_
#define collection_H_
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

template<class E, template <class...> class ContainerT>  
class collection{
	
public:
	collection(){}
	virtual E& iterator1()=0;
	virtual bool contains(E e)=0;
	virtual void clear()=0;
	virtual void addAll(collection& c)=0; 
	virtual void add(E e)=0;
	virtual bool isEmpty()=0;
	virtual int size()=0;
};



#endif /*collection_H_ */ 