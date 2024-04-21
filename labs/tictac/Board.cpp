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
void Board::maketurn(Move& move){
    int number = move.number;
    int row = move.row;
    int column = move.column;
    currentPlayer = move.player;
    if (board[row][column] != ' ') {
        throw InvalidMove("Square already taken.");
    }

    if (number != movecount + 1) {
        throw InvalidMove("Invalid move number.");
    }
    if (movecount != 0 && prevPlayer == currentPlayer) {
        throw InvalidMove("player repeat");
    }

    board[row][column] = currentPlayer;
    prevPlayer = currentPlayer;
    if(currentPlayer == 'X')
    {
        currentPlayer ='O';
    }
    else{
        currentPlayer ='X';
    }
    movecount++;

}
bool Board::isDraw(){
    if(movecount==9)
    {
        draw=true;
        return true;
    }
    draw=false;
    return false;
}
char Board::getsquare(int row, int col)const
{
    return board[row][col];
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
    else if(draw)
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