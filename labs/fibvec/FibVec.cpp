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
