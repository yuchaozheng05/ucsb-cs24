#ifndef BOARD_H
#define BOARD_H

#include "Move.h"

// I recommended writing a Board class to manage your game state.
// Here's some space for the class definition; member functions go in Board.cpp.

class Board {
private:
    char board[3][3]; 
    int moveCount;   
    char currentPlayer; 
    bool isWin(char player) const;
    bool isDraw() const;

public:
    Board();
    void makeMove(int number, char player, int row, int column);
    std::string printResult() const;
};
#endif
