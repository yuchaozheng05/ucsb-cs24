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
          int value;
          List::Node* node;
          HashTable* next;
          HashTable(std::string k, int v);
          ~HashTable();
       };
       HashTable** table;
       size_t capacity;
       size_t hash(const std::string& key)const;
       //size_t findtable(const std::string& key)const;
    public:
        Index(size_t capacity_ = 200);
        ~Index();
        void insert(const std::string& key, int value);
        void remove(const std::string& key, int value);
        void rehash(size_t newcapacity);
        List::Node* find(const std::string& key)const;
};
#endif