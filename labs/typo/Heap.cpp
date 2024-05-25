#include "Heap.h"
#include <stdexcept>
//#include <iostream>
Heap::Heap(size_t capacity)
{
    mData = new Entry[capacity];
    mCapacity = capacity;
    mCount = 0;
}

Heap::Heap(const Heap& other)
{
    mData = new Entry[other.mCapacity];
    mCapacity = other.mCapacity;
    mCount = other.mCount;
    for(size_t i =0; i<other.mCount; i++)
    {
        mData[i] = other.mData[i];
    }
}

Heap::~Heap()
{
    delete[] mData;
}

size_t Heap::capacity()const
{
    return mCapacity;
}

size_t Heap::count()const
{
    return mCount;
}

const Heap::Entry& Heap::lookup(size_t index)const{
    if(index>=mCount)
    {
        throw std::out_of_range("Index invalid");
    }
    return mData[index];
}

Heap::Entry Heap::pop()
{
    if(mCount == 0)
    {
        throw std::underflow_error("no item");
    }
    Entry lowest = mData[0];
    mData[0] = mData[mCount-1];
    //mCount--;
    size_t index = 0;
    while(true)
    {
        size_t left_child = index * 2 +1;
        size_t right_child = index * 2 +2;
        size_t i = index;
        if(left_child < mCount && mData[left_child].score < mData[i].score)
        {
             i = left_child;
        }
        if(right_child < mCount && mData[right_child].score < mData[i].score)
        {
             i = right_child;
        }
        if(i == index)
        {
            break;
        }
        Heap::Entry temp = mData[index];
        mData[index] = mData[i];
        mData[i] = temp;
        index=i;

    }
    return lowest;
}

Heap::Entry Heap::pushpop(const std::string& value, float score)
{
    if(mCount == 0)
    {
        throw std::underflow_error("no item");
    }
    Entry lowest = mData[0];
    mData[0].value = value;
    mData[0].score = score;
    size_t index = 0;
    while(true)
    {
        size_t left_child = index * 2 +1;
        size_t right_child = index * 2 +2;
        size_t i = index;
        if(left_child < mCount && mData[left_child].score < mData[i].score)
        {
             i = left_child;
        }
        if(right_child < mCount && mData[right_child].score < mData[i].score)
        {
             i = right_child;
        }
        if(i == index)
        {
            break;
        }
        Heap::Entry temp = mData[index];
        mData[index] = mData[i];
        mData[i] = temp;
        index=i;

    }
    return lowest;
}


void Heap::push(const std::string& value, float score)
{
    if(mCount == mCapacity)
    {
        throw std::overflow_error("no space");
    }
    mData[mCount].value = value;
    mData[mCount].score = score;
    size_t index = mCount;
    mCount++;
    while(index>0)
    {
        size_t parent_index = (index-1)/2;
        if(mData[index].score>= mData[parent_index].score)
        {
            break;
        }
        Heap::Entry temp = mData[index];
        mData[index] = mData[parent_index];
        mData[parent_index] = temp;
        index = parent_index;
    }
}

const Heap::Entry& Heap::top()const
{
    if(mCount == 0)
    {
        throw std::underflow_error("no item");
    }
    return mData[0];
}