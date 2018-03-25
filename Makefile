#Makefile
CXX = g++


Main: Main.o Determinant.o Matrix.o
	${CXX} Main.o Determinant.o Matrix.o -o Main

Main.o: Main.cpp
	${CXX} -c Main.cpp

Matrix.o: Matrix.cpp Matrix.hpp
	${CXX} -c Matrix.cpp

Determinant.o: Determinant.cpp Determinant.hpp
	${CXX} -c Determinant.cpp

clean:
	rm *.o Main
