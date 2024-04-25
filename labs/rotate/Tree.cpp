#include "Tree.h"
#include <stdexcept>
#include <iostream>

// Tree Function Implementations
Tree::Tree()
{
    head=nullptr;
}
Tree::~Tree()
{
    clear(head);
}
void Tree::clear(Node*& node){
    if(node!=nullptr)
    {
        clear(node->left);
        clear(node->right);
        delete node;
        node=nullptr;
    }
}
void Tree::clear()
{
    clear(head);
}
size_t Tree::count(Node* node)const{
    if(node == nullptr)
    {
        return 0;
    }
    return 1 + count(node->left) + count(node->right);
}
size_t Tree::count()const
{
    return count(head);
}
bool Tree::contains(Node* node, const std::string& s)const{
    if(node == nullptr)
    {
        return false;
    }
    if(node->value == s)
    {
        return true;
    }
    if(s< node->value)
    {
        return contains(node->left, s);
    }
    if(s>node->value)
    {
        return contains(node->right, s);
    }
    return false;
}
bool Tree::contains(const std::string& s)const{
    return contains(head, s);

}
int Tree::countweight(Node* node)const
{
    if(node == nullptr)
    {
        return 0;
    }
    return 1 + countweight(node->left) + countweight(node->right);
}
size_t Tree::find(Node* node, const std::string&s, size_t index)const{
    if(node == nullptr)
    {
        return count()-1;
    }
    if(node->value == s)
    {
        index += countweight(node->left);
        return index;
    }
    if(s < node->value)
    {
        return find(node->left, s, index);
    }
    if(s > node->value)
    {
        size_t left;
        if(node->left != nullptr)
        {
            left = countweight(node->left);
        }
        else{
            left = 0;
        }
        index += left + 1;
        return find(node->right, s, index);
    }
    return count()-1;
}
size_t Tree::find(const std::string& s)const{
    size_t index =0;
    return find(head, s, index);

}
