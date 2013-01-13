CXX = g++
INCLUDE = ../Utilities/
CXXFLAGS = -g -Wall

a.out: ConstructBinaryTree.o $(INCLUDE)BinaryTree.o
	$(CXX) -o a.out ConstructBinaryTree.o $(INCLUDE)BinaryTree.o
$(INCLUDE)BinaryTree.o: $(INCLUDE)BinaryTree.cpp $(INCLUDE)BinaryTree.h
	cd ../Utilities/ && $(MAKE)
ConstructBinaryTree.o: ConstructBinaryTree.cpp
	$(CXX) -I$(INCLUDE) $(CXXFLAGS) -c ConstructBinaryTree.cpp

clean:
	rm a.out *.o
