
#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>

int main() {
    Board board;
    std::string line;
    std::getline(std::cin,line);
    while (!line.empty())
    {
        try{
            Move move(line);
            board.maketurn(move);
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
        std::getline(std::cin,line);
    }
    std::cout << board.printresult()<<'\n';
    return 0;

}