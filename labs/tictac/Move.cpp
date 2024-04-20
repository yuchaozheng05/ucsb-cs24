#include "Errors.h"
#include "Move.h"
#include <cctype>
#include <sstream>
#include <istream>

// Space for implementing Move functions.

Move::Move(const std::string &input){
    std::istringstream text(input);
    std::string number_;
    text>>number_;
    number = std::stoi(number_);
    if(number<1 || number >9)
    {
        throw ParseError("Wrong number");
    }
    if(!isspace(input[1])){
        throw ParseError("Wrong input");
    }
    char playerletter;
    text>>std::ws>>playerletter;
    player = playerletter;
    player = toupper(player);
    if(player != 'X' && player != 'O')
    {
        throw ParseError("Invalid Player");
    }
    text>>std::ws;
    if(!isspace(input[3])){
        throw ParseError("wrong input");
    }
    char row_;
    char col_;
    text>>row_>>col_;
    column = col_ -'1';
    if(!isalpha(row_) && !isdigit(column))
    {
        throw ParseError("Invalid row or column");
    }
    row = row_ - 'A';
    row = toupper(row);
    if((row !=0 && row !=1 && row!=2) && (column!=1 && column !=0 && column !=2) )
    {
        throw ParseError("Invalid row or colunm letter");
    }
    row = toupper(row_)-'A';
    char nextchar;
    if(text>>std::ws>>nextchar){
        if(nextchar!='#')
        {
            throw ParseError("Invalid comment");
        }
        if(nextchar=='#')
        {
            if(!isspace(input[6])){
                throw ParseError("Invalid comment");
            }
        }
    }
}
std::string Move::to_string()const{
    std::ostringstream text;
    text<<number<<" "<<player<<" "<<char(row+'A')<<column+1;
    return text.str();

}