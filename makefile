all: List.o Queue.o Stack.o Poly.o
	g++ -o Poly List.o Queue.o Stack.o Poly.o
List.o: List.h List.cpp
	g++ -c List.h List.cpp
Queue.o: Queue.h Queue.cpp
	g++ -c Queue.h Queue.cpp
Stack.o: Stack.h Stack.cpp
	g++ -c Stack.h Stack.cpp
Poly.o: Poly.cpp
	g++ -c Poly.cpp
clean:
	rm -f *.o Poly
