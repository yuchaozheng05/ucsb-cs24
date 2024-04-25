#include "Tree.h"
#include <stdexcept>
#include <iostream>

// Tree Function Implementations
Tree::Tree()
{
    root=nullptr;
}
Tree::~Tree()
{
    clear(root);
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
    clear(root);
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
    return count(root);
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
    return contains(root, s);

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
    return find(root, s, index);
}
Node* Tree::insert(Node* node, const std::string& s)
{
    if(node == nullptr)
    {
       
        return new Node(s);
    }
    if(s < node->value)
    {
        node->left = insert(node->left, s);
    }
    if(s > node->value)
    {
        node->right = insert(node->right,s);
    }
    return reblanced(node);
}
void Tree::insert(const std::string& s)
{
    root = insert(root,s);
}
int Tree::inbalanced(Node* node)
{
    return countweight(node->right) - countweight(node->left);
}
Node* Tree::reblanced(Node* node)
{
    int balance = inbalanced(node);
    if (balance > 1) {
        int balance_ = inbalanced(node->right);
        if (balance_ < 0) 
        {
            node->right = right(node->right);
        }
        return Left(node);
    }
    if (balance < -1) {
        int balance_ = inbalanced(node->left);
        if (balance_ > 0) 
        {
            node->left = Left(node->left);
        }
        return right(node);
    }
    return node;
    
}
Node* Tree::Left(Node* temp)
{
    Node* a = temp->right;
    temp->right = a->left;
    a->left = temp;
    return a;
}
Node* Tree::right(Node* temp)
{
    Node* a = temp->left;
    temp->left = a->right;
    a->right = temp;
    return a;
}
std::string Tree:: lookup(size_t index)const{
    Node* temp = root;
    size_t num = count(root);
    std::string value;
    if(index >= num)
    {
        throw std::out_of_range("Index out of range");
    }
    size_t currentindex =0;
    value = lookup(temp,index,currentindex);
    return value;
   
}
std::string Tree::lookup(Node* node, size_t index, size_t& currentindex)const
{
    if(node == nullptr)
    {
        return "";
    }
    std::string left = lookup(node->left, index, currentindex);
    if(left != "")
    {
        return left;
    }
    if(currentindex == index)
    {
        return node->value;
    }
    currentindex++;
    return lookup(node->right, index, currentindex);
}
void Tree::printhelp(Node* node)const
{
    if(node == nullptr)
    {
        std::cout<<"-";
        exit(0);
    }
    
}
void Tree::print()const
{
    printhelp(root);
    std::cout<<"\n";
}
void Tree::remove(size_t index)
{
    lookup(index);
}
