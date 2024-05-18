#include "Counter.h"
#include "Iterator.h"

Counter::Counter()
{
    count_ = 0;
    total_ = 0;
}

Counter::~Counter()
{

}

size_t Counter::count()const
{
    return count_;
}

int Counter::total()const{
    return total_;
}

void Counter:: inc(const std::string& key, int by)
{
    List::Node* node = list.find(key);
    if (node != nullptr)
    {
        node->value += by;
    } 
    else 
    {
        insertNode(key, by);
    }
    total_ += by;
}

void Counter:: dec(const std::string& key, int by)
{
    List::Node* node = list.find(key);
    if (node != nullptr) 
    {
        node->value -= by;
    } 
    total_ -= by;
}

void Counter::del(const std::string& key) {
    List::Node* node = list.find(key);
    if (node != nullptr) {
        total_ -= node->value;
        removeNode(node);
        count_--;
    }
}

int Counter::get(const std::string& key)const
{
    List::Node* node = list.find(key);
    if(node != nullptr)
    {
        return node->value;
    }
    return 0;
}

void Counter::insertNode(const std::string& key, int value)
{
    list.addtail(key, value);
    count_++;
}

void Counter::removeNode(List::Node* node)
{
    list.remove(node);
    count_--;
}

void Counter::set(const std::string& key, int count)
{
    List::Node* node = list.find(key);
    if(node != nullptr)
    {
        total_ += (count - node->value);
        node->value = count;
    }
    else{
        insertNode(key, count);
        total_+=count;
    }
}

Counter::Iterator Counter::begin()const
{
    List::Node* headnode = list.gethead();
    return Counter::Iterator(headnode);
}

Counter::Iterator Counter::end()const
{
    return Counter::Iterator(nullptr);
}