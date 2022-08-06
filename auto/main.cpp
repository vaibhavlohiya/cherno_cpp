#include <iostream>
#include <vector>

std::string GetName()
{
    return "Vaibhav";
}

int main()
{
    auto a = 3.2f;
    auto name = GetName();
    std::cout << name << std::endl;

    std::vector<std::string> strings;
    strings.push_back("Apples");
    strings.push_back("Melons");

    for (auto it = strings.begin(); it != strings.end(); it++) // here auto helps us for a long type def of iterator
    {
        std::cout << *it << std::endl;
    }

    std::cin.get();
}