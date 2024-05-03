#include "Stack.h"
#include <sstream>

// Implement your Stack member functions here.
Stack::Stack()
{
    topvalue = nullptr;
    count =0;
}
Stack::Node::Node(AST* d, Node* n)
{
    data = d;
    next = n;
}
Stack::~Stack()
{
    while(!isEmpty())
    {
        delete pop();
    }
}
void Stack::push(AST* value)
{
    Node* temp = new Node(value, topvalue);
    topvalue = temp;
    count++;
}
AST* Stack::pop()
{
    if(isEmpty())
    {
        throw std::runtime_error("Not enough operands.");
    }
    Node* top = topvalue;
    //if (!top) { 
    //    throw std::runtime_error("Not enough operands.");
    //}
    AST* value = top->data;
    topvalue = top->next;
    delete top;
    count --;
    return value;

}

int Stack::size()const
{
    return count;
}
bool Stack::isEmpty()const
{
    if(topvalue == nullptr)
    {
        return true;
    }
    return false;
}


