#include "Errors.h"
#include "Board.h"
#include <iostream>

// Space for implementing Board functions.


Board::Board(){
    movecount=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            board[i][j]=' ';
        }
    }
}
void Board::maketurn(int number, int row, int col, char player){
    std::cout<<row<<' '<<col;
    if((row!=0 && row !=1 && row!=2)|| (col!=0 && col!=1 && col!=2))
    {
        throw InvalidMove("invalid row or col sb");
    }
    board[row][col] = player;
    movecount++;
    if(number != movecount)
    {
        throw InvalidMove("wrong move number");
    }
}
bool Board::isDraw()const{
    if(movecount==9)
    {
        return true;
    }
    return false;
}
bool Board::whowin(char player){
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
std::string Board::printresult(){
    if(movecount == 0)
    {
        return "Game in progress: New game.";
    }
    else if(whowin('X'))
    {
        return "Game over: X wins.";
    }
    else if(whowin('O'))
    {
        return "Game over: O wins.";
    }
    else if(isDraw())
    {
        return "Game over: Draw.";
    }
    else if(currentplayer =='X'){
        return "Game in progess: O's turn.";
    }
    else{
        return "Game in progess: X's turn.";
    }

}