CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter
CXX      = g++

.PHONY: all clean

all: main test

test: test.o Point.o WordList.o Heap.o
	${CXX} $(CXXFLAGS) -o $@ $+

main: main.o Point.o WordList.o Heap.o
	${CXX} $(CXXFLAGS) -o $@ $+

test.o: test.cpp Heap.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

main.o: main.cpp WordList.o
	${CXX} $(CXXFLAGS) -c -o $@ $<

Point.o: Point.cpp Point.h 
	${CXX} $(CXXFLAGS) -c -o $@ $<

WordList.o: WordList.cpp WordList.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

Heap.o: Heap.cpp Heap.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f test main test.o main.o Point.o WordList.o Heap.o