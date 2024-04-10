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
FibVec::FibVec()
{
    v = new int[1];
    fn=1;
    currentsize=0;
}
FibVec::~FibVec()
{
    delete[]v;
}
size_t FibVec::capacity()const{
    return fn;
}
size_t FibVec::count()const{
    return currentsize; 
}
void FibVec::insert(int value, size_t index){
    if(index>currentsize)
    {
        throw std::out_of_range("out of range");
    }
}
int FibVec::lookup(size_t index)const{
   if(index>currentsize)
    {
        throw std::out_of_range("out of range");
    } 
}
int FibVec::pop(){
    if(currentsize==0)
    {
        throw std::underflow_error("vector is empty");
    }
}
void FibVec::push(int value){
    insert(value, currentsize);
}
int FibVec::remove(size_t index){
   if(index>currentsize)
    {
        throw std::out_of_range("out of range");
    } 
    remove(index);
    return lookup(index); 
}



