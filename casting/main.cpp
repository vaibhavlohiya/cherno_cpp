// Casting in C++

#include <iostream>

class Base
{
public:
    Base() { }
    virtual ~Base() { }
    void print() const { std::cout << "hello" << std::endl;}
};

class Derived : public Base
{
public:
    Derived() { }
    ~Derived() { }
};

class AnotherClass : public Base
{
public:
    AnotherClass() { }
    ~AnotherClass() { }
};

int main()
{
    double value = 5.23;
    double a = (int)value + 5.3; // C style casting
    std::cout << a << std::endl;

    double s = static_cast<int>(value) + 5.3; // C++ style casting

    std::cin.get(); 
}