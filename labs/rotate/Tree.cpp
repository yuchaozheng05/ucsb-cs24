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
void Tree::updateweight(Node* node)const
{
    node->weight = 1+countweight(node->left) + countweight(node->right);
}
size_t Tree::find(Node* node, const std::string&s, size_t index)const{
    if(node == nullptr)
    {
        return __SIZE_MAX__;
    }
    if(s < node->value)
    {
        return find(node->left, s, index);
    }
    else if(s > node->value)
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
    else
    {

        size_t result = find(node->left, s, index);
        if(result == __SIZE_MAX__)
        {
            size_t currentindex = index + countweight(node->left);
            return currentindex;
        }
        return result;
        
    }
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
    else if(s <= node->value)
    {
        node->left = insert(node->left, s);
    }
    else if(s > node->value)
    {
        node->right = insert(node->right,s);
    }
    updateweight(node);
    return reblanced(node);
}
void Tree::insert(const std::string& s)
{
    root = insert(root,s);
}
int Tree::inbalanced(Node* node)
{
    if(node == nullptr)
    {
        return 0;
    }
    int balance = countweight(node->left) - countweight(node->right);
    return balance;
}
Node* Tree::reblanced(Node* node)
{
    int balance = inbalanced(node);
    if(balance == 0)
    {
        return node;
    }
    if(balance > 1 && inbalanced(node->left)>0)
    {
        return rotateRight(node);
    }
    else if (balance < -1 && inbalanced(node->right) < 0) 
    {
        return rotateLeft(node);
    }
    else if (balance > 1 && inbalanced(node->left) < 0) {
        node->left = rotateLeft(node->left); 
        return rotateRight(node); 
    }
    else if (balance < -1 && inbalanced(node->right) > 0) {
        node->right = rotateRight(node->right); 
        return rotateLeft(node); 
    }
    
    return node;
}
Node* Tree::rotateRight(Node* temp)//if left heavy
{
    Node* a = temp->left;
    Node* second= a->right;
    a->right = temp;
    temp->left = second;
    updateweight(temp);
    updateweight(a);
    return a;
}
Node* Tree::rotateLeft(Node* temp)//if right heavy
{
    Node* a = temp->right;
    Node* second= a->left;
    a->left = temp;
    temp->right = second;
    updateweight(temp);
    updateweight(a);
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
std::string Tree::printhelp(Node* node)const
{
    if(node==nullptr)
    {
        return "-";
    }
    if(!node->left && !node->right)
    {
        return node->value;
    }
    return "("+printhelp(node->left) +" "+ node->value +" "+ printhelp(node->right)+")";

}
void Tree::print()const
{
    Node* temp = root;
    std::cout<<printhelp(temp);
    std::cout<<std::endl;
}
Node* Tree::removehelp(Node* node, size_t index)
{
    if((node->left == nullptr)&& node->right == nullptr)
    {
        Node*temp = node;
        delete temp;
        return node;
    }
    return nullptr;
}
void Tree::remove(size_t index)
{
    Node* temp = root;
    size_t num = count();
    if(index>=num)
    {
        throw std::out_of_range("index out of range");
    }
    removehelp(temp, index);
}
std::string Tree::findsmallest(Node* node)
{
    if(node==NULL)
    {
        return " ";
    }
    else
    {
        if(node->left != NULL)
        {
            return findsmallest(node->left);
        }
        else{
            return node->value;
        }
    }
}