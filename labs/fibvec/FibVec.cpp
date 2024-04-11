#include "FibVec.h"

// This provides exception types:
#include <stdexcept>


// FibVec Function Implementation
size_t FibVec::fibnumber(size_t num){
    if(num==0){
        return 0;
    }
    if(num==1 || num==2)
    {
        return 1;
    }
    return fibnumber(num-1)+fibnumber(num-2);
}
void FibVec::resize(size_t new_fn){
  int*new_array = new int[new_fn];
  for(size_t i=0; i<array_count; i++)
  {
    new_array[i] = array_[i];
  }
  delete []array_;
  array_ = new_array;
  array_fnum = new_fn;
}
FibVec::FibVec()
{
    array_ = new int[1];
    array_fnum=1;
    array_count=0;
}
FibVec::~FibVec()
{
    delete[]array_;
}
size_t FibVec::capacity()const{
    return array_fnum;
}
size_t FibVec::count()const{
    return array_count; 
}
void FibVec::insert(int value, size_t index){
    if(index>array_count)
    {
        throw std::out_of_range("out of range");
    }
    if(array_count == array_fnum)
    {
        resize(fibnumber(array_fnum+1));
    }
    for(size_t i = array_count; i>index; i--)
    {
        array_[i]=array_[i-1];
    }
    array_[index]=value;
    array_count++;

}
int FibVec::lookup(size_t index)const{
   if(index>=array_count)
    {
        throw std::out_of_range("out of range");
    } 
    return array_[index];
}
int FibVec::pop(){
    if(array_count==0)
    {
        throw std::underflow_error("vector is empty");
    }
    int last_value = array_[array_count-1];
    resize(fibnumber(array_fnum-1));
    array_count -=1;
    return last_value;
}
void FibVec::push(int value){
    insert(value, array_count);
}
int FibVec::remove(size_t index){
   if(index>=array_count)
    {
        throw std::out_of_range("out of range");
    } 
    int ind_value = array_[index];
    for(size_t i=0; i<array_count; i++){
        if(i == index){
            array_[i]=array_[i+1];
        }
    }
    pop();
    return ind_value;
}



