// static in a global scope.

#include<iostream>

static int s_Variable = 5;

int main()
{
    std::cout << s_Variable << std::endl;
    std::cin.get();
}