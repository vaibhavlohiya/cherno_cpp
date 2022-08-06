// Macros in C++

#include <iostream>

// Macros are executed in the pre-processing stage and not in the compiling stage.
#define Wait std::cin.get()
#define Log(x) std::cout << x << std::endl

int main()
{
    Log("Hello");
    Wait;
}