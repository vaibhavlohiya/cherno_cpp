#include <iostream>

int main()
{
    //CONTINUE_STATEMENT
    for (int i = 0; i < 5; i++)
    {
        if (i % 2 == 0)
            continue;
        std::cout << "This will run when i is odd. " << i << std::endl;
    }

    std::cout << "x---x---x---x---x---x---x---x---x---x---x" << std::endl;

    //BREAK_STATEMENT
    for (int j = 0; j < 5; j++)
    {
        if ((j+1) % 2 == 0)
            break;
        std::cout << "This will run only once. " << j << std::endl;
    }

    std::cout << "x---x---x---x---x---x---x---x---x---x---x" << std::endl;

    //RETURN_STATEMENT
    for (int k = 0; k < 5; k++)
    {
        if ((k+1) % 2 == 0)
            return 0;
        std::cout << "This will run only once and the program will end. " << k << std::endl;
    }
    std::cin.get();
}