#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree {
  // Member Variables

  // Private Helper Functions
  Node* head;
  void clear(Node*& node);
  size_t count(Node* node)const;
  bool contains(Node* node, const std::string& s)const;
  Node* insert(Node* node, const std::string& s);
  void print(Node* node)const;
  Node* remove(Node* node, size_t index, size_t currentindex, bool& done);
  int countweight(Node* node)const;
  size_t find(Node* node, const std::string&s, size_t index)const;



public:
  Tree();
  ~Tree();

  // Public Member Functions
  void        clear();
  size_t      count() const;
  bool        contains(const std::string& s) const;
  size_t      find(const std::string& s) const;
  void        insert(const std::string& s);
  std::string lookup(size_t index) const;
  void        print() const;
  void        remove(size_t index);
};

#endif
