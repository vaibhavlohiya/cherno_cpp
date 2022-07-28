// Arrays in C++

#include <iostream>
#include <array>

#define PRINT(X) std::cout << X << std::endl

class Entity
{
public:
    static const int size = 5;
    int example[size];

    // Standard array
    std::array<int, 5> another;

    Entity()
    {   
        // Two different ways of using arrays
        
        for (int i = 0; i < size; i++)
            example[i] = 0;

        for (int i = 0; i < another.size(); i++)
            another[i] = 6;
    }
};

int main()
{
    int example[5];
    example[0] = 7;
    example[4] = 5;

    std::cout << example[0] << " " << example[4] << std::endl;
    std::cout << example << std::endl; // That just prints the memory address of example array.

    // For loop to assign values
    for (int i = 0; i < 5; i++)
    {
        example[i] = i*i;
        PRINT(example[i]);
    }

    // Pointers
    int* ptr = example;
    
    example[3] = 10;
    PRINT(example[3]);

    *(ptr + 3) = 12; // You can also access arrays through pointers like this. The number of bytes that is going to add depends on the data type.
    PRINT(example[3]);

    // Stack and heap allocation
    int ex[5]; // Stack allocated, will get deleted after the end of main function 
    int* another = new int[5]; // Heap allocated, won't get deleted unless specified.
    delete[] another;  

    // Standard array 
    Entity en;
    PRINT(en.example[2]);
    PRINT(en.another[1]);

    std::cin.get();
}