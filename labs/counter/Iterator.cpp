//#include "Counter.h"
#include "Iterator.h"

// Counter::Iterator Member Functions
Iterator::Iterator(List::Node* node)
{
    current = node;
}

const std::string& ::Iterator::key()const
{
    return current->key;
}

int Iterator::value()const
{
    return current->value;
}

void Iterator::operator++()
{
    if(current != nullptr)
    {
        current = current->next;
    }
}

bool Iterator::operator == (const Iterator& other)const
{
    if(current == other.current)
    {
        return true;
    }
    return false;
}

bool Iterator::operator != (const Iterator& other)const
{
    if(current != other.current)
    {
        return true;
    }
    return false;
}