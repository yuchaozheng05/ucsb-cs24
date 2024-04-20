#include "Errors.h"
#include "Board.h"
#include <iostream>

// Space for implementing Board functions.

Board::Board() {
    // Initialize the grid
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = ' ';
        }
    }
    moveCount = 0;
    currentPlayer = ' '; // No player starts the game initially
}

// Private member function to check if a move results in a win
bool Board::isWinningMove(int row, int col, char player) const {
    // Check row
    if (grid[row][0] == player && grid[row][1] == player && grid[row][2] == player)
        return true;
    // Check column
    if (grid[0][col] == player && grid[1][col] == player && grid[2][col] == player)
        return true;
    // Check diagonals
    if ((grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) ||
        (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player))
        return true;
    return false;
}

// Private member function to check if the game is a draw
bool Board::isDraw() const {
    return moveCount == 9;
}

// Public member function to make a move on the board
void Board::makeMove(int number, char player, int row, int column) {
    if (grid[row][column] != ' ') {
        throw InvalidMove("Square already occupied.");
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

    grid[row][column] = player;
    moveCount++;

    if (isWinningMove(row, column, player)) {
        std::cout << "Game over: " << player << " wins." << std::endl;
        exit(0);
    }

    if (isDraw()) {
        std::cout << "Game over: Draw." << std::endl;
        exit(0);
    }

    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Public member function to print the current state of the game
void Board::printResult() const {
    if (moveCount == 0) {
        std::cout << "Game in progress: New game." << std::endl;
    } else {
        std::cout << "Game in progress: " << currentPlayer << "'s turn." << std::endl;
    }
}