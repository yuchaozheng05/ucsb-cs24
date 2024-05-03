CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter
CXX      = g++

.PHONY: all clean

all: main test

test: test.o AST.o Nodes.o Stack.o
	${CXX} $(CXXFLAGS) -o $@ $+

main: main.o AST.o Nodes.o Stack.o
	${CXX} $(CXXFLAGS) -o $@ $+

test.o: test.cpp AST.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

main.o: main.cpp AST.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

AST.o: AST.cpp AST.h Nodes.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

Nodes.o: Nodes.cpp Nodes.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

Stack.o: Stack.cpp Stack.h AST.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f test main test.o main.o AST.o Nodes.o Stack.o
