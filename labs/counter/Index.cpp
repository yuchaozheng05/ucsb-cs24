#include "Index.h"

// Index Member Functions
Index::HashTable::HashTable(std::string k, int v)
{
    key =k;
    value = v;
    node = new List::Node(k,v);
}

Index::HashTable::~HashTable()
{
    delete node;
}

Index::Index(size_t capacity_)
{
    capacity = capacity_;
    table = new HashTable*[capacity];
    for(size_t i =0; i<capacity; i++)
    {
        table[i] = nullptr;
    }
}

Index::~Index() {
    for (size_t i = 0; i < capacity; ++i) {
        delete table[i];
    }
    delete[] table;
}

size_t Index::hash(const std::string& key)const
{
    size_t hashvalue = 0;
    for(char c:key)
    {
        hashvalue = c + (hashvalue << 6) + (hashvalue << 16) - hashvalue;
    }
    return hashvalue % capacity;
}

size_t Index::findtable(const std::string& key)const
{
    size_t start = hash(key);
    while(table[start] != nullptr && table[start]->key != key)
    {
        start = (start+1)%capacity;
    }
    return start;
}

void Index::insert(const std::string& key, int value)
{
    size_t start = findtable(key);
    if(table[start]!=nullptr && table[start]->key == key)
    {
        table[start]->value = value;
        table[start]->node->value = value;
    }
    else
    {
        table[start] = new HashTable(key, value);
    }
}

List::Node* Index::find(const std::string& key) const {
    size_t start = findtable(key);
    if (table[start] != nullptr && table[start]->key == key) {
        return table[start]->node;
    }
    return nullptr;
}

void Index::remove(const std::string& key) {
    size_t start = findtable(key);
    if (table[start] != nullptr && table[start]->key == key) {
        delete table[start];
        table[start] = nullptr;
    }
}

void Index::rehash(size_t newCapacity) {
    HashTable** oldTable = table;
    size_t oldCapacity = capacity;

    capacity = newCapacity;
    table = new HashTable*[capacity];
    for (size_t i = 0; i < capacity; ++i) {
        table[i] = nullptr;
    }

    for (size_t i = 0; i < oldCapacity; ++i) {
        if (oldTable[i] != nullptr) {
            insert(oldTable[i]->key, oldTable[i]->value);
            delete oldTable[i];
        }
    }

    delete[] oldTable;
}

