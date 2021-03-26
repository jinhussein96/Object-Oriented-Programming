


exe : rectangle.o circle.o triangle.o shape.o composedShape.o main.o polygon.o polyvec.o polydyn.o
	g++ -o exe rectangle.o circle.o shape.o triangle.o composedShape.o main.o polygon.o polyvec.o polydyn.o
polygon.o : polygon.cpp
	g++ -c -std=c++11 polygon.cpp
polyvec.o : polyvec.cpp
	g++ -c -std=c++11 polyvec.cpp
polydyn.o : polydyn.cpp
	g++ -c -std=c++11 polydyn.cpp
shape.o : shape.cpp
	g++ -c -std=c++11 shape.cpp
rectangle.o : rectangle.cpp
	g++ -c -std=c++11 rectangle.cpp
circle.o : circle.cpp
	g++ -c -std=c++11 circle.cpp
triangle.o : triangle.cpp
	g++ -c -std=c++11 triangle.cpp
composedShape.o : composedShape.cpp
	g++ -c -std=c++11 composedShape.cpp
main.o : main.cpp
	g++ -c -std=c++11 main.cpp
clean:
	rm *.o exe
