#include "Errors.h"
#include "Move.h"
#include <cctype>
#include <sstream>
#include <istream>
// Space for implementing Move functions.    

Move::Move(const std::string &input){
    std::istringstream text(input);
    unsigned walker = 0;
    if(text>>number){
        if (number < 1 || number > 9) {
            throw ParseError("Number out of bound");
        }
    } 
    else {
        throw ParseError("Not an number");
    }
    walker += 1;
    if(walker < input.size() && !isspace(input[walker])){
        throw ParseError("Wrong input, expect white space");
    }
    walker += 1;
    // consider case if multiple white spaces exist
    while(walker < input.length() && isspace(input[walker])){
        walker+=1;
    }
    char playerletter;
    text>>std::ws>>playerletter;
    player = playerletter;
    player = toupper(player);
    if(player != 'X' && player != 'O')
    {
        throw ParseError("Invalid Player: " + player);
    }
    walker += 1;
    if(walker < input.length() &&!isspace(input[walker])){
        throw ParseError("wrong input");
    }
    walker += 1;
    while (walker < input.length() && isspace(input[walker])){
        walker +=1;
    }
    std::string rowcol;
    text>>std::ws>>rowcol;
    if(rowcol.size()!=2)
    {
        throw ParseError("wrong rowcol");
    }
    char row_, col_;
    row_ = rowcol[0];
    col_ = rowcol[1];
    if(!isalpha(row_)||!isdigit(col_))
    {
        throw ParseError("Invalid row or column");
    }
    column = col_ -'1';
    row = toupper(row_) - 'A';
    if((row !=0 && row !=1 && row!=2) || (column!=0 && column !=1 && column !=2) )
    {
        throw ParseError("Invalid row or colunm letter");
    }
    walker += 2;
    // mark the required field ending places
    unsigned lastPos = walker;

    // Optionally, whitespace, count if any 
    while (walker < input.length() && isspace(input[walker]))
    {
        walker += 1;
    }
    //Optionally, a comment, whitespaces required
    char comment;
    text>>std::ws;
    if(text>>comment) 
    {
        if(input[walker]!='#')
        {
            throw ParseError("Wrong input on comment");
        }
        if(comment == '#')
        {
            if(lastPos == walker)
            {
                // no preceeding whitespace
                throw ParseError("Invalid comment space");
            }
        }
        else{
            throw ParseError("Wrong comment");
        }
    }
}

std::string Move::to_string()const{
    std::ostringstream text;
    text<<number<<" "<<player<<" "<<char(row+'A')<<column+1;
    return text.str();

}
