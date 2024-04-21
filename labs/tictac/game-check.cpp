#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>

int main() {
    Board board;
    std::string line;
    bool gameOver = false;
    while (std::getline(std::cin,line))
    {
        try{
            Move move(line);
            board.makeTurn(move);
            if (board.printresult().find("Game over") != std::string::npos) {
                gameOver = true;
                break;
            }
        }
        catch(const ParseError& e)
        {
            std::cout<<"Parse error.\n";
            return 1;    
        }
        catch(const InvalidMove& e)
        {
            std::cout<<"Invalid move.\n";
            return 2;
        }
    }
    if (!gameOver) {
        std::cout << board.printresult() << '\n';
    }
    return 0;

}