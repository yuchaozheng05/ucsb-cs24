#include "Nodes.h"

#include <sstream>
#include <string>

// This creates the number format the autograder expects:
std::string format(double number) {
  std::ostringstream stream;
  stream << number;
  return stream.str();
}


// Implement your AST subclasses' member functions here.
Number::Number(double number)
{
  num = number;
}

std::string Number::prefix()const
{
  return std::to_string(num);
}

std::string Number::postfix()const
{
  return std::to_string(num);
}

double Number::value()const
{
  return num;
}

Opertor::Opertor(char opertor, AST* leftnode, AST* rightnode)
{
  oper = opertor;
  left = leftnode;
  right = rightnode;
}
Opertor::~Opertor()
{
  delete left;
  delete right;
}

std::string Opertor::prefix()const
{
  //std::string result;
  return oper + " " + left->prefix() + " " + right->prefix();
  //return result;

}

std::string Opertor::postfix()const
{
  // std::string result;
  return left->postfix() + " " + right->postfix() + " " + oper;
  // return result;
}

double Opertor::value()const
{
  double leftvalue = left->value();
  if(oper == '~')
  {
    double value = -1 * leftvalue;
    return value;
  }
  double rightvalue = right->value();
  if(oper == '+')
  {
    return leftvalue + rightvalue;
  }
  else if(oper == '-')
  {
    return leftvalue - rightvalue;
  }
  else if(oper == '*')
  {
    return leftvalue * rightvalue;
  }
  else if (oper == '/')
  {
    if(rightvalue == 0)
    {
      throw std::runtime_error("Division by zero");
    }   
     return leftvalue / rightvalue;
  }
  else if (oper == '%')
  {
    if(rightvalue == 0)
    {
      throw std::runtime_error("Division by zero");
    }
    return leftvalue - (rightvalue * int(leftvalue/rightvalue));
  }
  else
  {
    throw std::runtime_error("opertor no accept");
  }
}
