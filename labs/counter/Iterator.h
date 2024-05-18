#ifndef ITERATOR_H
#define ITERATOR_H
#include "List.h"

class Iterator {
    // Member Variables
    List::Node* current;

  public:
    Iterator(List::Node* node);
    const std::string& key() const;
    int value() const;

    void operator ++ ();
    bool operator == (const Iterator& other) const;
    bool operator != (const Iterator& other) const;
  };


  #endif
