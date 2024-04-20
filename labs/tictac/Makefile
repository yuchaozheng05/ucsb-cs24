CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter
CXX      = g++

.PHONY: all clean

all: move-check game-check


move-check: Move.o move-check.o
	${CXX} $(CXXFLAGS) -o $@ $+

move-check.o: move-check.cpp Move.h
	${CXX} $(CXXFLAGS) -c -o $@ $<
	
Move.o: Move.cpp Move.h 
	${CXX} $(CXXFLAGS) -c -o $@ $<

game-check: game-check.o Board.o Move.o 
	$(CXX) $(CXXFLAGS) -o game-check game-check.o Board.o Move.o 
	
game-check.o: game-check.cpp
	$(CXX) $(CXXFLAGS) -c game-check.cpp

Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) -c Board.cpp

clean:
	rm -f  move-check Move Board game-check 
