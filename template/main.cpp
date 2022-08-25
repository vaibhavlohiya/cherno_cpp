// Templates in C++

#include <iostream>

template<typename T>
void Print(T value) // This function is created only when it is called in the main, otherwise
// it is just a template.
{
    std::cout << value << std::endl;
}


int main()
{
    // Variable types are defined implicitely
    Print(5);
    Print("vaibhav");
    Print(5.89f);

    // Variable types are defined explicitely (we can do this but we dont have to)
    Print<int>(5);
    Print<const char*>("Lohiya");

    std::cin.get();
}