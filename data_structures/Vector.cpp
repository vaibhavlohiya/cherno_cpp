#include <iostream>

#include "Vector.h"

int main()
{
    Vector<std::string> vector;

    vector.PushBack("Hello");
    vector.PushBack("my name is");
    vector.PushBack("Vaibhav");

    for (size_t i = 0; i < vector.Size(); i++)
        std::cout << vector[i] << std::endl;
    
    std::cout << vector.Size() << std::endl;
}