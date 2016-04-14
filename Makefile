CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic-errors -std=c++11

all : casexample sequential main

casexample : casexample.cpp
	$(CXX) -o casexample casexample.cpp $(CXXFLAGS)

sequential : casexample.cpp
	$(CXX) -o sequential casexample.cpp $(CXXFLAGS)

main :
	$(CXX) -o main main.cpp BST.cpp SequentialBST.cpp NonBlockingBST.cpp $(CXXFLAGS)

clean :
	rm -f casexample sequential main *.o
