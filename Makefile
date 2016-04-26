CXX=g++
CXXFLAGS=-c -Wall -Wextra -pedantic-errors -std=c++11
LDFLAGS=-latomic
SOURCES=BST.cpp SequentialBST.cpp NonBlockingBST.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLES=BST

all : $(OBJECTS) $(EXECUTABLES)

.cpp.o :
	$(CXX) $(CXXFLAGS) $< -o $@

$(EXECUTABLES) : $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

clean :
	rm -f $(EXECUTABLES) *.o
	rm -f casexample

casexample : casexample.cpp
	$(CXX) $(CXXFLAGS) casexample.cpp
	$(CXX) $(LDFLAGS) casexample.o -o casexample
