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
        else{
            int neededOperands = (token == "~") ? 1 : 2;
            if (stack.size() < neededOperands) {
                throw std::runtime_error("Not enough operands.");
            }
        }
        if(token == "+")
        {
            
            AST* right = stack.pop();
            AST* left = stack.pop();
            stack.push(new Opertor('+', left, right ));
        }
        else if(token == "-")
        {
           
            AST* right = stack.pop();
            AST* left = stack.pop();
            stack.push(new Opertor('-', left, right ));
        }
        else if(token == "*")
        {
            
            AST* right = stack.pop();
            AST* left = stack.pop();
            stack.push(new Opertor('*', left, right ));
        }
        else if(token == "/")
        {
            
            AST* right = stack.pop();
            AST* left = stack.pop();
            stack.push(new Opertor('/', left, right ));
        }
        else if(token =="~")
        {
            
            AST* left = stack.pop();
            stack.push(new Opertor('~',left,nullptr));
        }
        else if(token == "%")
        {
            
            AST* right = stack.pop();
            AST* left = stack.pop();
            stack.push(new Opertor('%', left, right ));
        }
        else{
            throw std::runtime_error("Invalid token: " + token);
        }

    }
    //return 0;
    if(stack.isEmpty())
    {
        throw std::runtime_error("No input.");
    }
     if(stack.size()>1)
    {
      throw std::runtime_error("Too many operands.");
    }
         
    return stack.pop();
}