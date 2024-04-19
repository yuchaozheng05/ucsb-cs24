#include "Errors.h"
#include "Move.h"
#include <cctype>
#include <sstream>
#include <istream>

// Space for implementing Move functions.

Move::Move(const std::string &input){
    std::istringstream text(input);
    text>>number;
    if(number<1 || number >9)
    {
        throw ParseError("Wrong number");
    }
    text>>std::ws;
    text>>player;
    player = toupper(player);
    if(player != 'X' && player !='O')
    {
        throw ParseError("Invalid Player");
    }
    text>>std::ws;
    char row_;
    char col_;
    text>>row_>>col_;
    row = toupper(row_) -'A';
    column = col_ -'1';
    if(!isalpha(row_) || !isdigit(col_))
    {
        throw ParseError("Invalid row or column");
    }
    if(row==0 || row!=1 || row!=2 || column!=0 || column !=1 || column !=2 )
    {
        throw ParseError("Invalid row or colunm");
    }
    char nextchar;
    if(text>>std::ws>>nextchar && nextchar!='#')
    {
        throw ParseError("Invalid comment");
    }
}
std::string Move::to_string()const{
    std::ostringstream text;
    text<<number<<" "<<toupper(player)<<" "<<char('A'+row)<<char('1'+column);
    return text.str();

}