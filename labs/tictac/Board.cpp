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

bool Board::isWin(char player) {
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

bool Board::isDraw() {
    if(moveCount == 9)
    {
        return true;
    }
    return false;
}

void Board::makeMove(int number, char player, int row, int column) {
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


std::string Board::printResult(){
    if(moveCount == 0)
    {
        return "Game in progress: New game.";
    }
    else if(isWin('X'))
    {
        return "Game over: X wins.";
    }
    else if(isWin('O'))
    {
        return "Game over: O wins.";
    }
    else if(isDraw())
    {
        return "Game over: Draw.";
    }
    else if(currentPlayer =='X'){
        return "Game in progess: O's turn.";
    }
    else{
        return "Game in progess: X's turn.";
    }
}