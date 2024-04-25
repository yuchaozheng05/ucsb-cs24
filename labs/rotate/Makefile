CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter
CXX      = g++

.PHONY: all clean

all: test

test: test.o Tree.o
	${CXX} $(CXXFLAGS) -o $@ $+


test.o: test.cpp Tree.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

Tree.o: Tree.cpp Tree.h Node.o
	${CXX} $(CXXFLAGS) -c -o $@ $<

Node.o: Node.cpp Node.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f test test.o Tree.o Node.o
