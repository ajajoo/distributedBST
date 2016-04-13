CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic-errors -std=c++11

all : casexample sequential

casexample : casexample.cpp
	$(CXX) -o casexample casexample.cpp $(CXXFLAGS)

sequential : casexample.cpp
	$(CXX) -o sequential casexample.cpp $(CXXFLAGS)

clean :
	rm -f casexample sequential *.o
