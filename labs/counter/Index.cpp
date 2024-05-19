
#include "Index.h"

// Index Member Functions
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
        HashTable* e = table[i];
        while(e != nullptr)
        {
            HashTable* next = e->next;
            delete e;
            e=next;
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
    HashTable* newEntry = new HashTable(key, node);
    newEntry->next = table[idx];
    table[idx] = newEntry;
    ++size;
}

// Find node by key
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

// Remove key-node pair
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
        } else {
            prev->next = entry->next;
        }
        delete entry;
        --size;
    }
}

// Rehash to a new capacity
void Index::rehash(size_t newCapacity) {
    HashTable** oldTable = table;
    size_t oldCapacity = capacity;

    capacity = newCapacity;
    table = new HashTable*[capacity];
    for (size_t i = 0; i < capacity; ++i) {
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

