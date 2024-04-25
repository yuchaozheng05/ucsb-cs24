#ifndef NODE_H
#define NODE_H

#include <string>

struct Node {
  // TODO!
  std::string value;
  Node* left;
  Node* right;
  Node* next;
  int weight;
  Node(const std::string& value);
 

};

#endif
