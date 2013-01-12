all: mytest
CXX = g++
INCLUDE = ../Utilities/
CXXFLAGS = -g -Wall

all:
	cd ../Utilities/ && $(MAKE)

mytest: PrintListInReversedOrder.o $(INCLUDE)List.o
	$(CXX) -o mytest PrintListInReversedOrder.o $(INCLUDE)List.o
PrintListInReversedOrder.o: PrintListInReversedOrder.cpp
	$(CXX) -I$(INCLUDE) $(CXXFLAGS) -c PrintListInReversedOrder.cpp

clean:
	rm mytest *.o
