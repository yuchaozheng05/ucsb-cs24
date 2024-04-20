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
            board.makeMove(move.number, move.player, move.row, move.column);
            board.printResult();
        } catch (const ParseError& e) {
            std::cerr << "Parse error: " << e.what() << std::endl;
            return 1;
        } catch (const InvalidMove& e) {
            std::cerr << "Invalid move: " << e.what() << std::endl;
            return 2;
        }
    }

    return 0;
}