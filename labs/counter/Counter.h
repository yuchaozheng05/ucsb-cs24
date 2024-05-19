#ifndef COUNTER_H
#define COUNTER_H


#include <cstddef>
#include <string>
#include "List.h"
#include "Iterator.h"
#include "Index.h"

// This is the Counter class you need to implement.
// It includes the Counter::Iterator as a nested class.

class Counter {

private:
  // Member Variables
  List list;
  size_t count_;
  int total_;
  Index index;

private:
  // Helper Functions
  void insertNode(const std::string& key, int value);
  void removeNode(List::Node* node);

public:
  using Iterator = ::Iterator;
public:
  Counter();
  ~Counter();

  size_t count() const;
  int    total() const;

  void inc(const std::string& key, int by = 1);
  void dec(const std::string& key, int by = 1);
  void del(const std::string& key);
  int  get(const std::string& key) const;
  void set(const std::string& key, int count);

  Iterator begin() const;
  Iterator end() const;
};

#endif
