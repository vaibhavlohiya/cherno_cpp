#include <iostream>

int Multiply(int a, int b) // A function to multiply between two numbers.
{
    return a * b;
}

void Multiply_and_Log(int a, int b) // A function to multiply and log the ouput on the terminal.
{
    int result = Multiply(a, b);
    std::cout << result << std::endl;
}

int main()
{
    int result = Multiply(4, 5);
    std::cout << result << std::endl;

    Multiply_and_Log(3, 7);
    Multiply_and_Log(81, 78);

    std::cin.get();
}