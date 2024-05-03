#include "AST.h"
#include "Nodes.h"
#include "Stack.h"
#include <sstream>
#include <iostream>

bool isnumber(const std::string& input) {
    size_t index =0;
    bool hasdigit=false;
    bool hasdecimal=false;
    if (input.empty()) {
        return false;
    }
    if(input.size()==1)
    {
        if(isdigit(input[0]))
        {
            return true;
        }
    }
    if(input[index]=='+' || input[index]=='-')
    {
        index++;
        if(index == input.size())
        {
            return false;
        }
    }
    for(; index<input.size(); index++)
    {
        if(isdigit(input[index]))
        {
            hasdigit = true;
        }
        else if(input[index]=='.')
        {
            if(hasdecimal)
            {
                return false;
            }
            hasdecimal = true;
        }
        else{
            return false;
        }
    }
    return hasdigit;
}
AST* AST::parse(const std::string& expression) {
    std::string token;
    std::istringstream stream(expression);
    Stack stack;
    while(stream >> token) {
        //size_t length = token.size();
        if(isnumber(token))
        {
            //std::cout<<"is number !!! ";
            AST* node = new Number(std::stod(token));
            stack.push(node);
        }
        if(token == "+")
        {
            AST* left = stack.pop();
            AST* right = stack.pop();
            stack.push(new Opertor('+', left, right ));
        }
        if(token == "-")
        {
            AST* left = stack.pop();
            AST* right = stack.pop();
            stack.push(new Opertor('-', left, right ));
        }
        if(token == "*")
        {
            AST* left = stack.pop();
            AST* right = stack.pop();
            stack.push(new Opertor('*', left, right ));
        }
        if(token == "/")
        {
            AST* left = stack.pop();
            AST* right = stack.pop();
            stack.push(new Opertor('/', left, right ));
        }
        if(token =="~")
        {
            AST* left = stack.pop();
            stack.push(new Opertor('~',left,nullptr));
        }

    }
    //return 0;
    return stack.pop();
}