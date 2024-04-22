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
      bool gameover;


    public:
      Board();
      bool whowin(char player)const;
      bool isDraw()const;
      char getsquare(int row, int col)const;
      std::string printresult();
      void maketurn(Move& move);
      bool isGameover()const;


};
#endif

