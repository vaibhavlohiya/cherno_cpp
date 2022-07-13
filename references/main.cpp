#include <iostream>

#define LOG(x) std::cout << x << std::endl

void increment(int& value)
{
    value++;
}

int main()
{
    int a = 5;
    int& ref = a;        //references are always with the variable declaration.
    //ref = 2;             // references only exist in the source code it doesn't acquire memory. It is just an alias.

    ref = 8;   // a = 8, b = 8  which means you cannot use one reference to more than one variable.

    increment(a);
    LOG(a);

}
