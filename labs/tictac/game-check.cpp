#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>

int main(int argc, char** argv) {
  bool verbose = false;

  if(argc == 2 && std::string(argv[1]) == "-v") {
    verbose = true;
  }

  if(verbose) {
    std::cout << "> ";
  }
  Board board;
  std::string line;
  int count =0;
  while (std::getline(std::cin,line))
    {
      if(line.empty())
      {
        if(count == 0)
        {
          std::cout<<"Game in progress: New game.\n";
          return 0;
        }
        if(count<=9)
        {
           std::cout << board.printresult() << '\n';
           return 0;
        }
      }
        try{
            Move move(line);
            board.makeTurn(move);
            count +=1;
  
        }
        catch(const ParseError& e)
        {
            if(verbose) {
              std::cout << "Parse error: " << e.what() << '\n';
            }
            else{
              std::cout<<"Parse error.\n";
            }
            return 1;    
        }
        catch(const InvalidMove& e)
        {
            if(verbose) {
              std::cout << "InvalidMove: " << e.what() << '\n';
              }
              else{
                std::cout<<"Invalid move.\n";
              }
            return 2;
        }
    }
    std::cout << board.printresult() << '\n';
    return 0;

}