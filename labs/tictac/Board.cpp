
#include "Errors.h"
#include "Board.h"
#include <iostream>

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
void Board::makeTurn(Move& move){
    int number = move.number;
    int row = move.row;
    int column = move.column;
    char player = move.player;
    if (board[row][column] != ' ') {
        throw InvalidMove("Square already taken.");
    }

    if (number != movecount+1) {
        throw InvalidMove("Invalid move number.");
    }
    if(movecount>0)
    {
        if(player!=currentPlayer)
        {
            throw InvalidMove("Player repeat");
        }
    }
    currentPlayer = player;
    if(currentPlayer == 'X')
    {
        currentPlayer ='O';
    }
    else{
        currentPlayer ='X';
    }
    board[row][column] = player;
    movecount++;

}
bool Board::isDraw()const{
    if(movecount==9)
    {
        return true;
    }
    return false;
}
char Board::getSquare(int row, int col)const
{
    return board[row][col];
}
bool Board::whoWins(char player)const{
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
std::string Board::printresult()const{ 
    if(movecount == 0)
    {
        return "Game in progress: New game.";
        exit(0);
    }
    else if(whoWins('X'))
    {
        return "Game over: X wins.";
        exit(0);
    }
    else if(whoWins('O'))
    {
        return "Game over: O wins.";
        exit(0);
    }
    else if(isDraw())
    {
        return "Game over: Draw.";
        exit(0);
    }
    else if(currentPlayer =='X'){
        return "Game in progess: O's turn.";
        exit(0);
    }
    else{
        return "Game in progess: X's turn.";
        exit(0);
    }


}