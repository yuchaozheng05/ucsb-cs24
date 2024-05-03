#ifndef STACK_H
#define STACK_H
#include "AST.h"
// Use this file to define your Stack type.
// Implement its member functions in Stack.cpp.
class Stack
{
private:
    struct Node{
        AST* data;
        Node* next;
        Node(AST* value, Node* nextone);
    };
    Node* topvalue;
public:
   Stack();
   ~Stack();
   void push(AST* value);
   AST* pop();
   AST* top()const;
   
};
#endif
