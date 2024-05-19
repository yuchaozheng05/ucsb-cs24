
#ifndef INDEX_H
#define INDEX_H
#include <string>
#include "List.h"

// TODO..
class Index{
    private:
       struct HashTable
       {
          std::string key;
          List::Node* node;
          HashTable* next;
          HashTable(const std::string& k, List::Node* n);
          ~HashTable();
       };
       HashTable** table;
       size_t capacity;
       size_t hash(const std::string& key)const;
       size_t size;
       
    public:
        Index(size_t capacity_ = 200);
        ~Index();
        void insert(const std::string& key, List::Node* node);
        void remove(const std::string& key);
        void rehash(size_t newcapacity);
        List::Node* find(const std::string& key)const;
};
#endif