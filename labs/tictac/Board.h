#ifndef BOARD_H
#define BOARD_H

#include "Move.h"

// I recommended writing a Board class to manage your game state.
// Here's some space for the class definition; member functions go in Board.cpp.

class Board{
    private:
      char board[3][3];
      int movecount;
      char currentplayer;

    public:
      Board();
      bool whowin(char player);
      bool isDraw() const;
      std::string printresult();
      void maketurn(int number, int row, int col, char player);

};
#endif
