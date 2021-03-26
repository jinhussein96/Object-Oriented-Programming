


exe : Rectangle.o Circle.o Triangle.o composedShape.o 151044079_main.o
	g++ -o exe 151044079_main.o Rectangle.o Circle.o Triangle.o composedShape.o
composedShape.o : composedShape.cpp
	g++ -c -std=c++11 composedShape.cpp


Rectangle.o : Rectangle.cpp
	g++ -c -std=c++11 Rectangle.cpp

Circle.o : Circle.cpp
	g++ -c -std=c++11 Circle.cpp
Triangle.o : Triangle.cpp
	g++ -c -std=c++11 Triangle.cpp
151044079_main.o : 151044079_main.cpp
	g++ -c -std=c++11 151044079_main.cpp
clean:
	rm *.o exe
