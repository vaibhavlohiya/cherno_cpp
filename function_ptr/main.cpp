#include <iostream>
#include <vector>

void Printvalue(int value)
{
    std::cout << "Values: " << value << std::endl;
}

void Foreach(std::vector<int> values, void(*func)(int))
{
    for (int value : values)
        func(value);
}

void Hello(int x)
{
    std::cout << "Hello World!" << x << std::endl;
}

int main()
{
    // simple function
    Hello(1);

    // you can use auto to call a function pointer 
    auto func = Hello;
    func(2);

    // you can also use typedef 
    typedef void(*HelloWorld)(int);
    HelloWorld function = Hello; 

    function(3);

    // using vector 
    std::vector<int> values = {1, 2, 3, 4, 5};
    Foreach(values, Printvalue);

    // using lamda function
    Foreach(values, [](int value) { std::cout << "Value: " << value << std::endl; });


    std::cin.get();
}