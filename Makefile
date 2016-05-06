ifeq ($(shell hostname), mc18.cs.purdue.edu)
	CXX=g++-5.3.0
else
	CXX=g++
endif
CXXFLAGS=  -c -Wall -Wextra -pedantic-errors -std=c++11 -mcx16 -pthread -fgnu-tm
LDFLAGS=-latomic
SOURCES=BST.cpp SequentialBST.cpp NonBlockingBST.cpp main.cpp
STMSOURCE = STMbst.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLES=BST
PF = -lpthread
all : $(OBJECTS) $(EXECUTABLES) 
	$(CXX) -pthread -std=c++11  -fgnu-tm STMbst.cpp 
	mv a.out STMbst
	      	
.cpp.o :
	$(CXX) $(CXXFLAGS) $< -o $@

$(EXECUTABLES) : $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@ $(PF)

clean :
	rm -f $(EXECUTABLES) *.o
	rm -f casexample
	rm -f STMbst

casexample : casexample.cpp
	$(CXX) $(CXXFLAGS) casexample.cpp
	$(CXX) $(LDFLAGS) casexample.o -o casexample

	
