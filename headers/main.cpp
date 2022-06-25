#include <iostream>
#include "log.h"

int main()
{
    InitLog();
    Log("Hello World!");
    std::cin.get();
}