#include <iostream>

#define LOG(x) std::cout << x << std::endl
int main()
{
    void* ptr = NULL;
    LOG("The value of the pointer: " << ptr);
    LOG("The memory address of the pointer: " << &ptr);

    int var = 8;
    int* pointer = &var; // & is for de-referencing the pointer to get the date from the memory address.
    *pointer = 10;
    LOG("The value of var is changed from pointer: " << var);

    std::cin.get();
}



