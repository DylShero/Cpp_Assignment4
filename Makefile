# Makefile for assignment 4 of C++ programming.
CXX = g++
CXXFLAGS := -std=c++23 -Wextra -Wall  
LDFLAGS  := -lstdc++exp

TARGET = assignment4

# Final executable
$(TARGET): assignment4.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) assignment4.o $(LDFLAGS)

# Object file target
assignment4.o: String.cc String.h
	$(CXX) $(CXXFLAGS) -c String.cc -o assignment4.o

.PHONY: clean

clean:
	rm -f $(TARGET) *.o