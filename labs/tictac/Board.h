#ifndef BOARD_H
#define BOARD_H

#include "Move.h"

// I recommended writing a Board class to manage your game state.
// Here's some space for the class definition; member functions go in Board.cpp.

class Board{
    private:
      char board[3][3];
      int movecount;
      char currentPlayer;
      bool isDraw()const;


    public:
      Board();
      char getSquare(int row, int col)const;
      std::string printresult()const;
      void makeTurn(Move& move);
      bool whoWins(char player)const;

};
#endif
