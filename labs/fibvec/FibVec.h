#ifndef FIBVEC_H
#define FIBVEC_H

// This provides the size_t type:
#include <cstddef>

class FibVec {
  // Member Variables
  int *array_;
  size_t array_fnum;
  size_t array_count;
  void resize(size_t new_fn);

  // Helper Functions
  size_t fibnumber(size_t num);
  size_t next_fibnumber(size_t num);
  size_t prev_fibnumber(size_t num);


public:
  // Constructor and Destructor
  FibVec();
  ~FibVec();
  size_t capacity()const;
  size_t count()const;
  void insert(int value, size_t index);
  int lookup(size_t index)const;
  int pop();
  void push(int value);
  int remove(size_t index);


  // Member Functions

};

#endif
