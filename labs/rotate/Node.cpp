#include "Node.h"

// Node Function Implementations
Node::Node(const std::string& val){
    value = val;
    left=nullptr;
    right=nullptr;
    next = nullptr;
    weight =1;
}
