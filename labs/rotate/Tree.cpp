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
    node->weight =  1 + countweight(node->left) + countweight(node->right);
    return node->weight;
}
void Tree::updateweight(Node* node)const
{
    node->weight = countweight(node);
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
    if(s <= node->value)
    {
        node->left = insert(node->left, s);
        updateweight(node);
        return reblanced(node);
    }
    else 
    {
        node->right = insert(node->right,s);
        updateweight(node);
        return reblanced(node);
    }
    updateweight(node);
    //return reblanced(node);
    return node;
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

bool Tree::isrotate(Node* node)
{
   int balance = inbalanced(node);
   //std::cout<<"balance for "<<node->value<<" is "<<balance<<std::endl;
   if (balance >1) {  // Left heavy
      
       int rotbalance = countweight(node->right) + 1;// + countweight(node->left->right);
       if(node->left != nullptr)
       {
         rotbalance += countweight(node->left->right);
         rotbalance -= countweight(node->left->left);
       }
       //std::cout<<"rotbalance for "<<node->value<<" after rotate is "<<rotbalance<<std::endl;
       if (std::abs(rotbalance) < std::abs(balance)) {
           return true;
       }
   } 
   if(balance < -1) {  // Right heavy
       
       int rotbalance = countweight(node->left) + 1;//+ countweight(node->right->left);
        //std::cout<<"rotbalance for "<<node->value<<" after rotate is "<<rotbalance<<std::endl;
        if(node->right != nullptr)
        {
            rotbalance+= countweight(node->right->left);
            rotbalance-= countweight(node->right->right);
        }
       if (std::abs(rotbalance) < std::abs(balance)) {
           return true;
       }
   }
   return false;
}
//
Node* Tree::reblanced(Node* node)
{
   if (node == nullptr) 
   {
       return nullptr;
   }
   updateweight(node);  // Make sure weights are correct before checking balance
   int balance = inbalanced(node);
   if(balance == 0)
   {
    return node;
   }
   if (isrotate(node)) {  // If rotation can reduce imbalance
       if (balance > 1 ) //left heavy
       {
           return rotateRight(node);  // Rotate right if left-heavy
       } 
       if (balance < -1 ) //right heavy
       {
           return rotateLeft(node);  // Rotate left if right-heavy
       }
   }
   

   return node; 
}

Node* Tree::rotateRight(Node* temp)//if left heavy
{
    if(temp == nullptr || temp->left == nullptr)
    {
        return temp;
    }
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
    if(temp == nullptr || temp->right == nullptr)
    {
        return temp;
    }
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

std::string Tree::printhelp(Node* node) const {
    if (node == nullptr) {
        return "-";  
    }
    if (!node->left && !node->right) {
        return node->value;
    }
    std::string leftPart;
    if(node->left == nullptr)
    {
        leftPart ="-";
    }   
    else
    {
        leftPart=printhelp(node->left);
    }
    std::string rightPart; 
    if(node->right == nullptr)
    {
        rightPart="-";
    }
    else{
        rightPart=printhelp(node->right);
    }
    return "(" + leftPart + " " + node->value + " " + rightPart + ")";
}
void Tree::print()const
{
    Node* temp = root;
    std::cout<<printhelp(temp);
    std::cout<<std::endl;
}
Node* Tree::removehelp(Node* node, std::string s)
{
     if (node == nullptr) {
        throw std::out_of_range("Index out of range");
    }
    else if(s < node->value)
    {
        node->left = removehelp(node->left, s);
    }
    else if(s > node->value)
    {
        node->right = removehelp(node->right, s);
    }
    else{
        if(node->left == nullptr)//if one child
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if(node->right == nullptr)//if one child
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        else//two child
        {
            Node* temp = findsmallest(node->right);
            node->value = temp->value;
            node->right = removehelp(node->right, temp->value);
        }
    }
    return reblanced(node);
}
void Tree::remove(size_t index)
{
    std::string s = lookup(index);
    root = removehelp(root, s);

}
Node* Tree::findsmallest(Node* node)
{
    Node* curr = node;
    while (curr && curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}










