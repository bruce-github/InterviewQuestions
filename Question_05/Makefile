CXX = g++
INCLUDE = ../Utilities/
CXXFLAGS = -g -Wall

a.out: PrintListInReversedOrder.o $(INCLUDE)List.o
	$(CXX) -o mytest PrintListInReversedOrder.o $(INCLUDE)List.o
$(INCLUDE)List.o: $(INCLUDE)List.cpp $(INCLUDE)List.h
	cd ../Utilities/ && $(MAKE)
PrintListInReversedOrder.o: PrintListInReversedOrder.cpp
	$(CXX) -I$(INCLUDE) $(CXXFLAGS) -c PrintListInReversedOrder.cpp

clean:
	rm mytest *.o
