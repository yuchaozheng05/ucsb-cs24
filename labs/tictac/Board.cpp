#include "Errors.h"
#include "Board.h"
#include <iostream>

// Space for implementing Board functions.

Board::Board() {
    // Initialize the grid
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
    moveCount = 0;
    currentPlayer = ' '; 
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

void Board::makeMove(int number, char player, int row, int column) {
    if (board[row][column] != ' ') {
        throw InvalidMove("Square already taken.");
    }

    if (number != moveCount + 1) {
        throw InvalidMove("Invalid move number.");
    }

    if (player != 'X' && player != 'O') {
        throw InvalidMove("Invalid player.");
    }

    if (moveCount != 0 && player == currentPlayer) {
        throw InvalidMove("Players must alternate.");
    }

    board[row][column] = player;
    moveCount++;

    if (isWin(player)) {
        std::cout << "Game over: " << player << " wins." << std::endl;
        exit(0);
    }

    if (isDraw()) {
        std::cout << "Game over: Draw." << std::endl;
        exit(0);
    }

    if(currentPlayer == 'X')
    {
        currentPlayer ='O';
    }
    else{
        currentPlayer ='X';
    }
}

// Public member function to print the current state of the game
void Board::printResult() const {
    if (moveCount == 0) {
        std::cout << "Game in progress: New game." << std::endl;
    } 
    else {
        std::cout << "Game in progress: " << currentPlayer << "'s turn." << std::endl;
    }
}