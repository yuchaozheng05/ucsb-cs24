#ifndef LIST_H
#define LIST_H
#include <iostream>
// TODO...
class List{
    public:
      struct Node
      {
         std::string key;
         int value;
         Node* prev;
         Node* next;
         Node(std::string k, int v);
      };
      List();
      ~List();
      void addtail(const std::string& key, int value);
      Node* find(const std::string& key)const;
      void remove(const std::string& key, int value);
      Node* gethead()const;
      Node* gettail()const;
      
    private:
    Node* head;
    Node* tail;
};
#endif
