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
    if(isspace(input[0]))
    {
        throw ParseError("extra space");
    }
    if(!isspace(input[1])){
        throw ParseError("Wrong input");
    }
    char playerletter;
    text>>std::ws>>playerletter;
    player = playerletter;
    player = toupper(player);
    if(isspace(input[2]))
    {
        throw ParseError("extra space");
    }
    if(player != 'X' && player != 'O')
    {
        throw ParseError("Invalid Player");
    }
    if(!isspace(input[3])){
        throw ParseError("wrong input");
    }
    char row_;
    char col_;
    text>>std::ws>>row_>>col_;
    column = col_ -'1';
    if(isspace(input[4]))
    {
        throw ParseError("extra space");
    }
    if(!isalpha(row_) && !isdigit(column))
    {
        throw ParseError("Invalid row or column");
    }
    row = toupper(row_) - 'A';
    if((row !=0 && row !=1 && row!=2) || (column!=1 && column !=0 && column !=2) )
    {
        throw ParseError("Invalid row or colunm letter");
    }
    if(isspace(input[5]))
    {
        throw ParseError("Extra space");
    }
    std::string comment;
    if(text>>std::ws>>comment) 
    {
        if(comment[0] != '#'){
            throw ParseError("Invalid comment");
        }
        if(comment[0] == '#')
        {
            if(!isspace(input[6]))
            {
                throw ParseError("Invalid comment space");
            }
            if(isspace(input[7]))
            {
                throw ParseError("extra space on comment");
            }
        }
    }
}
std::string Move::to_string()const{
    std::ostringstream text;
    text<<number<<" "<<player<<" "<<char(row+'A')<<column+1;
    return text.str();

}