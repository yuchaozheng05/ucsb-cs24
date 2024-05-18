#include "Counter.h"

// Counter::Iterator Member Functions
Counter::Iterator::Iterator(List::Node* node)
{
    current = node;
}

const std::string& Counter::Iterator::key()const
{
    return current->key;
}

int Counter::Iterator::value()const
{
    return current->value;
}

void Counter::Iterator::operator++()
{
    if(current != nullptr)
    {
        current = current->next;
    }
}

bool Counter::Iterator::operator == (const Iterator& other)const
{
    if(current == other.current)
    {
        return true;
    }
    return false;
}

bool Counter::Iterator::operator != (const Iterator& other)const
{
    if(current != other.current)
    {
        return true;
    }
    return false;
}