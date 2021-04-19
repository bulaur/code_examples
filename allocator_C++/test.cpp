#include <iostream>
#include <cstdlib>
#include "allocator.h"

int main() 
{
    makeAllocator(1000);

    // first test 
    // checking difference between 2 alloc()
    std::cout << "Test 1:\n";
    char* p1 = alloc(100);
    char* p2 = alloc(200);
    if (p1 == p2) 
    {
        std::cout << "Error\n";
        return 1;
    }
    else 
    {
        std::cout << "Complited\n";
    }

    // second test
    // checking reset()
    std::cout << "Test 2:\n";
    reset();
    p2 = alloc(100);
    if (p1 != p2)
    {
        std::cout << "Error\n";
        return 1;
    }
    else 
    {
        std::cout << "Complited\n";
    }

    // third test
    // checking alloc() with a suprerior size of memory
    std::cout << "Test 3: \n";
    reset();
    p1 = alloc(2000);
    if (p1 != nullptr) 
    {
        std::cout << "Error\n";
        return 1;
    }
    else 
    {
        std::cout << "Complited\n";
    }
    
    delAllocator();
}