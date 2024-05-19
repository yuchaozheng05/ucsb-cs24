
#include "List.h"
#include <iostream>
// List Member Functions
List::Node::Node(std::string k, int v)
{
    key = k;
    value = v;
    prev = nullptr;
    next = nullptr;
}
List::List()
{
    head = nullptr;
    tail = nullptr;
}

List::~List()
{
    Node* curr = head;
    while(curr != nullptr)
    {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
}

List::Node* List::addtail(const std::string &key, int value)
{
    Node* newnode = new Node(key, value);
    if(head == nullptr)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
    return newnode;
}

List::Node* List::find(const std::string &key)const
{
    Node* curr = head;
    while(curr != nullptr)
    {
        if(curr->key == key)
        {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

void List::remove(const std::string& key, int value)
{
   Node* node = find(key);
   if (node == nullptr) 
   {
      return;
   }

    if (node->prev != nullptr) 
    {
        node->prev->next = node->next;
    } 
    else {
        head = node->next;
    }

    if (node->next != nullptr) {
        node->next->prev = node->prev;
    } 
    else {
        tail = node->prev;
    }
    delete node;
}

List:: Node* List::gethead()const
{
    return head;
}

List:: Node* List::gettail()const
{
    return tail;
}