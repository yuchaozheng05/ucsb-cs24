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
    char playerletter;
    text>>playerletter;
    player = playerletter;
    if(player != 'X' || player !='O' || player != 'x' || player !='o')
    {
        throw ParseError("Invalid Player");
    }
    text>>std::ws;
    char row_;
    char col_;
    text>>row_>>col_;
    row_ = toupper(row_);
    row = row_ -'A';
    column = col_ -'1';
    if(!isalpha(row_) || !isdigit(column))
    {
        throw ParseError("Invalid row or column");
    }
    if(row_!='A' || row_!='B' || row_!='C' || column!=0 || column !=1 || column !=2 )
    {
        throw ParseError("Invalid row or colunm");
    }
    char nextchar;
    if(text>>std::ws>>nextchar){
        if(nextchar!='#')
        {
            throw ParseError("Invalid comment");
        }
    }
}
std::string Move::to_string()const{
    std::ostringstream text;
    text<<number<<" "<<toupper(player)<<" "<<row+'A'<<column+1;
    return text.str();

}