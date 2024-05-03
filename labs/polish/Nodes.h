#ifndef NODES_H
#define NODES_H

#include "AST.h"

// Declare your AST subclasses here.
// Implement their member functions in Nodes.cpp.
class Number: public AST{
private:
    double num;
public:
    Number(double num);
    virtual std::string prefix()  const;
    virtual std::string postfix() const;
    virtual double      value()   const;
};

class Opertor: public AST{
private:
    char oper;
    AST* left;
    AST* right;
public:
    Opertor(char oper, AST* leftnode, AST* rightnode);
    virtual ~Opertor();
    virtual std::string prefix()  const;
    virtual std::string postfix() const;
    virtual double      value()   const;
};
#endif
