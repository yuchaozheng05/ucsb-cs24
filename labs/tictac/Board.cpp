#include "Errors.h"
#include "Board.h"
#include <iostream>

// Space for implementing Board functions.

Board::Board() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
    moveCount = 0;
}

bool Board::isWin(char player) const {
    for(int i=0; i<3;i++)
    {
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
        {
            return true;
        }
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player)
        {
            return true;
        }
    }
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
    {
        return true;
    }
    if(board[2][0]==player && board[1][1]==player && board[0][2]==player)
    {
        return true;
    }
   
    return false;
}

bool Board::isDraw() const {
    if(moveCount == 9)
    {
        return true;
    }
    return false;
}

void Board::makeMove(const Move &move) {
    int row = move.row;
    int column = move.column;
    int number = move.number;
    char player= move.player;
    if (board[row][column] != ' ') {
        throw InvalidMove("Square already taken.");
    }

    if (number != moveCount + 1) {
        throw InvalidMove("Invalid move number.");
    }

    if (moveCount != 0 && player == currentPlayer) {
        throw InvalidMove("player repeat");
    }

    board[row][column] = player;
    moveCount++;

    if(currentPlayer == 'X')
    {
        currentPlayer ='O';
    }
    else{
        currentPlayer ='X';
    }
}

// Public member function to print the current state of the game
std::string Board::printResult() const {
    if (moveCount == 0) {
        return "Game in progress: New game.";
    } 
    else if (isWin('X')) {
        return "Game over: X wins.";
        exit(0);
    }
    else if (isWin('O')) {
        return "Game over: O wins.";
        exit(0);
    }

    else if (isDraw()) {
        return "Game over: Draw.";
        exit(0);
    }
    else if(currentPlayer == 'X')
    {
        return "Game in progress: O's turn.";
    }
    else{
        return "Game in progress: X's turn.";
    }
    
}