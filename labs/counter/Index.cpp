
#include "Index.h"


Index::HashTable::HashTable(const std::string& k, List::Node* n)
{
    key =k;
    node = n;
    next = nullptr;
}

Index::HashTable::~HashTable()
{
    //delete node;
}

Index::Index(size_t capacity_):capacity(capacity_), size(0)
{
    table = new HashTable*[capacity];
    for(size_t i =0; i<capacity; i++)
    {
        table[i] = nullptr;
    }
}

Index::~Index() {
    for (size_t i = 0; i < capacity; ++i) {
        HashTable* current = table[i];
        while(current != nullptr)
        {
            HashTable* next = current->next;
            delete current;
            current=next;
        }

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

void Index::insert(const std::string& key, List::Node* node) {
    if (size >= capacity / 2) {
        rehash(capacity * 2);
    }

    size_t idx = hash(key);
    HashTable* newtable = new HashTable(key, node);
    if(table[idx]==nullptr)
    {
        table[idx] = newtable;
    }
    else
    {
        newtable->next = table[idx];
        table[idx] = newtable;
    }
    size++;
}

List::Node* Index::find(const std::string& key) const {
    size_t idx = hash(key);
    HashTable* entry = table[idx];

    while (entry != nullptr) {
        if (entry->key == key) {
            return entry->node;
        }
        entry = entry->next;
    }
    return nullptr;
}


void Index::remove(const std::string& key) {
    size_t idx = hash(key);
    HashTable* entry = table[idx];
    HashTable* prev = nullptr;

    while (entry != nullptr && entry->key != key) {
        prev = entry;
        entry = entry->next;
    }

    if (entry != nullptr) {
        if (prev == nullptr) {
            table[idx] = entry->next;
        } 
        else {
            prev->next = entry->next;
        }
        delete entry;
        size--;
    }
}

void Index::rehash(size_t newCapacity) {
    HashTable** oldTable = table;
    size_t oldCapacity = capacity;
    table = new HashTable*[newCapacity];
    for (size_t i = 0; i < newCapacity; ++i) {
        table[i] = nullptr;
    }

    for (size_t i = 0; i < oldCapacity; ++i) {
        HashTable* entry = oldTable[i];
        while (entry != nullptr) {
            insert(entry->key, entry->node);
            HashTable* next = entry->next;
            delete entry;
            entry = next;
        }
    }
    delete[] oldTable;
}

