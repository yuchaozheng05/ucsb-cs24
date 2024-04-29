#ifndef TREE_H
#define TREE_H

#include "Node.h"


class Tree {
  // Member Variables

  // Private Helper Functions
  Node* root;
  void clear(Node*& node);
  size_t count(Node* node)const;
  bool contains(Node* node, const std::string& s)const;
  Node* insert(Node* node, const std::string& s);
  std::string print(Node* node)const;
  Node* remove(Node* node, size_t index, size_t currentindex, bool& done);
  int countweight(Node* node)const;
  size_t find(Node* node, const std::string&s, size_t index)const;

  Node* reblanced(Node* node);
  int inbalanced(Node* node);
  Node* rotateLeft(Node* node);
  Node* rotateRight(Node* node);
  std::string lookup(Node*node, size_t index, size_t& currentindex)const;
  std::string printhelp(Node* node)const;
  Node* removehelp(Node* node, std::string s);
  Node* findsmallest(Node* node);
  void updateweight(Node* node)const;
  bool isrotate(Node* node);
  void update(Node* node);
  


  




public:
  Tree();
  ~Tree();

  // Public Member Functions
  void        inOrder()const;
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
