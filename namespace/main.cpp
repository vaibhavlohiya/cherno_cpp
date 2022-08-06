// Namespace in C++ (They are used in C++ to avoid naming conflicts.)

#include <iostream>
#include <algorithm>

namespace apple
{
    void print(const char* text)
    {
        std::cout << text << std::endl;
    }
}

namespace orange
{
    void print(const char* text)
    {
        std::string temp = text;
        std::reverse(temp.begin(), temp.end());
        std::cout << temp << std::endl;
    }
}

int main()
{
    namespace a = apple;
    a::print("Hello");
    orange::print("Hello");

    std::cin.get();
}