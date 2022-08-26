#include <iostream>
#include <array>
#include <cstring>

#include "Array.h"

int main()
{
    int size = 5;
    Array<int, 6> data;

    static_assert(data.Size() < 10, "Size is too large!!");

    // making all the value of array to be 0
    memset(data.Data(), 0, data.Size() * sizeof(int));

    data[0] = 2;
    data[4] = 7;
    
    for (size_t i = 0; i < data.Size(); i++)
        std::cout << data[i] << std::endl;

    std::cin.get();
}