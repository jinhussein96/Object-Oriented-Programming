#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "collection.cpp"
#include "collection.h"
#include "arrayList.h"
#include "arrayList.cpp"
#include "LIST.h"
#include "ITERATOR.h"
using namespace std;
int main(){
	std::vector<int> v;
	arrayList<int,std::vector> f;
	f.add(1);
	f.add(9);
	f.add(2);	
	f.add(4);
	f.add(6);
	cout<<"size = ";
	cout<<f.size()<<endl;
	cout<<f.contains(1)<<endl;
	if(!(f.isEmpty()))
	cout<<"vector is not empty"<<endl;
	f.clear();
	if((f.isEmpty()))
	cout<<"vector is  empty"<<endl;
	

	return 0;
} 