#include "Errors.h"
#include "Move.h"
#include <cctype>
#include <sstream>
#include <istream>

// Space for implementing Move functions.

Move::Move(const std::string &input){
    char number_, player_, row_, col_;
    number_=input[0];
    number = number_ -'0';
    if(number < 1 || number >9)
    {
        throw ParseError("Invalid movenumber");
    }
    if(!isspace(input[1]))
    {
        throw ParseError("extra space before player");
    }
    player_ = input[2];
    player = toupper(player_);
    if(player != 'X' && player != 'O')
    {
        throw ParseError("Invalid player");
    }
    if(!isspace(input[3]))
    {
        throw ParseError("extra space before row");
    }
    row_ = input[4];
    col_=input[5];
    column = col_ -'1';
    if(!isalpha(row_) && !isdigit(column))
    {
        throw ParseError("Invalid row or column");
    }
    row = toupper(row_) - 'A';
    if((row !=0 && row !=1 && row!=2) || (column!=1 && column !=0 && column !=2) )
    {
        throw ParseError("Invalid row or colunm letter");
    }
    if(input.size()>7)
    {
        if(!isspace(input[6]))
        {
            throw ParseError("Invalid space before comment");
        }
        char comment;
        comment = input[7];
        if(comment != '#')
        {
            throw ParseError("Invalid comment");
        }
    }
}
std::string Move::to_string()const{
    std::ostringstream text;
    text<<number<<" "<<player<<" "<<char(row+'A')<<column+1;
    return text.str();

}