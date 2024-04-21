
#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>

int main() {
    Board board;
    std::string line;
    while (std::getline(std::cin,line))
    {
        try{
            Move move(line);
            board.makeTurn(move);
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
        if (board.Gameover()) {
            break;
        }

    }
    std::cout << board.printresult() << '\n';
    return 0;

}