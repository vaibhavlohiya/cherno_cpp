#include<iostream>

enum Example
{
    A, B, C,  //If you don't initialize the value the first one will be 0 then 1 and so on.

};

enum Example_2 : unsigned char // You can assign a data type by this.
{
    D = 5, E, F
};

int main()
{
    Example_2 value = F;

    std::cout << value << std::endl;
    std::cin.get();
}