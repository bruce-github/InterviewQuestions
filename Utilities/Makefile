OBJS = List.o BinaryTree.o

all: $(OBJS)

List.o: List.cpp List.h
	$(CXX) $(CXXCFLAGS) -c List.cpp
BinaryTree.o: BinaryTree.h BinaryTree.cpp
	$(CXX) $(CXXCFLAGS) -c BinaryTree.cpp

clean:
	rm *.o
