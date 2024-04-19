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
    if(!isspace(input[1])){
        throw ParseError("Wrong input");
    }
    char playerletter;
    text>>playerletter;
    player = playerletter;
    if(player != 'X' || player !='O' || player != 'x' || player !='o')
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
    if(!isalpha(row_) || !isdigit(column))
    {
        throw ParseError("Invalid row or column");
    }
    if(row_!='A' || row_!='B' || row_!='C' || row_!='a' || row_!='b' || row_!='c' || column!=0 || column !=1 || column !=2 )
    {
        throw ParseError("Invalid row or colunm");
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
    text<<number<<" "<<toupper(player)<<" "<<char(row+'A')<<column+1;
    return text.str();

}