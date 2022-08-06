#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

void Foreach(const std::vector<int> values, const std::function<void(int)>& func)
{
    for (int value : values)
        func(value);
}

int main()
{
    
    std::vector<int> values = {1, 2, 3, 4, 5};
    auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3; });
    
    std::cout << *it << std::endl; // dereference it

    int a = 5;

    auto lambda = [=](int value) { std::cout << "Value: " << value << a << std::endl; }; // [] is called a captcha
    Foreach(values, lambda);


    std::cin.get();
}