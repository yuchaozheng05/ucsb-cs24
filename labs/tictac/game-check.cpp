#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>

int main() {
    Board board; // Initialize the game board
    std::string line;

    while (std::getline(std::cin, line)) {
        try {
            Move move(line);
            board.makeMove(move);
            std::cout<<board.printResult()<<'\n';
        } 
        catch (const ParseError& e) {
            std::cout<<"Parse error: " <<e.what()<<'\n';
            return 1;
        } 
        catch (const InvalidMove& e) {
            std::cout << "Invalid move: " << e.what()<<'\n';
            return 2;
        }
    }


    return 0;
}