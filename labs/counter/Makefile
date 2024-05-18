CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror -Wno-unused-parameter
CXX      = g++

.PHONY: all clean

all: main char-count word-count

char-count: main.o Counter.o Index.o List.o Iterator.o
	${CXX} $(CXXFLAGS) -o $@ $+

main: main.o Counter.o Index.o List.o Iterator.o
	${CXX} $(CXXFLAGS) -o $@ $+

word-count: main.o Counter.o Index.o List.o Iterator.o
	${CXX} $(CXXFLAGS) -o $@ $+

char-count.o: char-count.cpp Counter.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

main.o: main.cpp Counter.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

AST.o: AST.cpp AST.h Nodes.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

word-count.o: word-count.cpp Counter.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

Counter.o: Counter.cpp Counter.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

Iterator.o: Iterator.cpp Counter.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

Index.o: Index.cpp Index.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

List.o: List.cpp List.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f main char-count word-count main.o char-count.o word-count.o Counter.o Index.o List.o Iterator.o
