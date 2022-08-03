// Strings in C++

#include <iostream>
#include <string>

void PrintName(const std::string& Name) { std::cout << Name << std::endl; }

int main()
{   
    // Old way

    const char* name = "Lohiya";
    char name_2[8] = { 'V', 'a', 'i', 'b', 'h', 'a', 'v', 0 }; // 0 == '\0' 
    
    std::cout << name << std::endl;
    std::cout << name_2 << std::endl;

    // New way

    std::string hello = std::string("Hello") + " Ji"; // two ways to add into a string.
    hello += " Kya haal hai ?";
    std::cout << hello.size() << std::endl;
    std::cout << hello << std::endl;

    PrintName("My name is Vaibhav");

    std::cin.get();
}