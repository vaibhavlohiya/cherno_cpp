#include <iostream>
#include <vector>

#include <unordered_map>

int main()
{
    /*std::vector<int> values = { 1, 2, 3, 4, 5, 6 };

    // normal 'for' loop
    for (int i = 0; i < values.size(); i++) 
        std::cout << values[i] << std::endl;

    // range based 'for' loop
    for (int value : values)
        std::cout << value << std::endl;

    // std vector iterator
    for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
        std::cout << *it << std::endl;

    */

    // use of iterators in unordered map
    using iter = std::unordered_map<std::string, int> ;

    iter map;
    map["cherno"] = 5;
    map["c++"] = 4;

    // first method
    for (iter::const_iterator it = map.begin(); it != map.end(); it++)
    {
        auto& key = it->first;
        auto& value = it->second;

        std::cout << key << " = " << value << std::endl;
    }

    // second method
    for (auto kv : map)
    {
        auto& key = kv.first;
        auto& value = kv.second;

        std::cout << key << " = " << value << std::endl;
    }

    // third method (works in c++17 and above) use clang++
    for (auto [key, value] : map)
        std::cout << key << " = " << value << std::endl;

    std::cin.get();
}