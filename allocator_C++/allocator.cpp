#include <iostream>
#include <cstdlib>
#include "allocator.h"

char* alloc_ptr_begin = nullptr;
char* alloc_ptr_curr = nullptr;
size_t alloc_mem_left = 0;
size_t alloc_mem_total = 0;

void makeAllocator(size_t maxSize) 
{// create a allocator with linear memory strategy
    alloc_ptr_begin = (char*) malloc(sizeof(char) * maxSize);
    if (alloc_ptr_begin == nullptr) return;
    // if malloc return nullptr
    // retain variables like makeAllocator() haven't called

    alloc_ptr_curr = alloc_ptr_begin;
    alloc_mem_left = maxSize;
    alloc_mem_total = maxSize;
}

char* alloc(size_t size) 
{// allocate size byte 
    if (alloc_mem_left > size)
    {
        char* alloc_space = alloc_ptr_curr;
        alloc_ptr_curr += size;
        alloc_mem_left -= size;

        return alloc_space;
    }
    
    return nullptr;
}

void reset() 
{// renull all used memory
 // move ptr_curr into begin
    alloc_ptr_curr = alloc_ptr_begin;
    alloc_mem_left = alloc_mem_total;
}

void delAllocator(void) 
{// finish work with allocator
 // free used memory
    free(alloc_ptr_begin);
    alloc_ptr_begin = nullptr;
    alloc_ptr_curr = nullptr;
    alloc_mem_left = 0;
    alloc_mem_total = 0;
}