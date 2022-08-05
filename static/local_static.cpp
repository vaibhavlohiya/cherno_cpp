// Local static in C++

#include <iostream>

class Singleton
{
public:
    static Singleton& Get() 
    {
        // even though this is static in this scope, the lifetime of instance is till the end of the program.
        static Singleton instance; 
        return instance;
    }

    void Hello() {}
};

void function()
{
    static int i = 0;
    i++;
    std::cout << i << std::endl;
}

int main()
{
    Singleton::Get().Hello(); 

    function();
    function();
    function();
    std::cin.get();
}