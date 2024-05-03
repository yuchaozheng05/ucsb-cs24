#include "Stack.h"

// Implement your Stack member functions here.
Stack::Stack()
{
    topvalue = nullptr;
}
Stack::Node::Node(AST* d, Node* n)
{
    data = d;
    next = n;
}
Stack::~Stack()
{
    delete topvalue;
}
void Stack::push(AST* value)
{
    Node* temp = new Node(value, topvalue);
    topvalue = temp;
}
AST* Stack::pop()
{
    Node* top = topvalue;
    AST* value = top->data;
    topvalue = top->next;
    delete top;
    return value;

}
AST* Stack::top()const
{
    return topvalue->data;
}


