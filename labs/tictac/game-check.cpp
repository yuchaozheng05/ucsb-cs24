#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>

int main() {
    Board board; 
    std::string line;

    while (std::getline(std::cin, line)) {
        try {
            Move move(line);
            board.makeMove(move.number, move.player, move.row, move.column);
            board.printResult();
        } catch (const ParseError& e) {
            std::cout << "Parse error: \n" ;
            return 1;
        } catch (const InvalidMove& e) {
            std::cerr << "Invalid move: \n";
            return 2;
        }
    }

    return 0;
}