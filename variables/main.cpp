#include <iostream>

int main()
{
    // int (4-bytes)

    unsigned int var = 8;  // unsigned is used for non-negative values.

    std::cout << var << std::endl;
    std::cout << sizeof(var) << " bytes" << std::endl; // to get the size of unsigned int

    std::cout << "x----x----x-----x-----x-----x----x" << std::endl; 

    // float (4-bytes) and double (8-bytes)

    float var_1 = 5.5f; // if you don't put an f at the end it will consider it a double 
    double var_2 = 4.1;

    std::cout << var_1 << std::endl;
    std::cout << sizeof(var_1) << " bytes" << std::endl;

    std::cout << "x----x----x-----x-----x-----x----x" << std::endl; 

    std::cout << var_2 << std::endl;
    std::cout << sizeof(var_2) << " bytes" << std::endl;

    // char (1-byte)

    char character = 'A';

    std::cout << character << std::endl;
    std::cout << sizeof(character) << " bytes" << std::endl;

    // bool (1-byte)

    bool binary = true;

    std::cout << binary << std::endl;
    std::cout << sizeof(binary) << " bytes" << std::endl;
 
    std::cin.get();

}