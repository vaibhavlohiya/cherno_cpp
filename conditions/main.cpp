#include <iostream>

int main()
{
    const char* ptr = "Hello";

    if (ptr)
        std::cout << ptr << std::endl;
    else if (ptr == "Hello") // This won't run because if statement is true however it will run when 'if' is there
        std::cout << "ptr is Hello" << std::endl;
    else
        std::cout << "ptr is null" << std::endl;
    
    std::cin.get();
}