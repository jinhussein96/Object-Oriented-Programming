exe :  collection.o  arrayList.o main.o ITERATOR.o
	g++ -o exe collection.o  arrayList.o main.o ITERATOR.o

collection.o : collection.cpp
	g++ -c -std=c++11 collection.cpp
ITERATOR.o : ITERATOR.cpp
	g++ -c -std=c++11 ITERATOR.cpp
arrayList.o : arrayList.cpp
	g++ -c -std=c++11 arrayList.cpp
main.o : main.cpp
	g++ -c -std=c++11 main.cpp
clean:
	rm *.o exe
