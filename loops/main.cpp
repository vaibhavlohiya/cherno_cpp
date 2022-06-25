#include <iostream>

int main()
{
    //FOR_LOOP

    //METHOD_1
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Hello World!" << std::endl;
    }

    std::cout << "x---x---x---x---x---x---x---x---x---x---x" << std::endl;

    //METHOD_2
    int j = 0;
    for ( ; j < 5; )
    {
        std::cout << "Hello World!" << std::endl;
        j++;
    }

    std::cout << "x---x---x---x---x---x---x---x---x---x---x" << std::endl;

    //METHOD_3
    int k = 0;
    bool condition = true;
    for (; condition; )
    {
        std::cout << "Hello World!" << std::endl;
        k++;
        if (!(k < 5))
            condition = false;
    }

    std::cout << "x---x---x---x---x---x---x---x---x---x---x" << std::endl;

    //WHILE_LOOP

    //METHOD_1
    int x = 0;
    while (x < 5)
    {
        std::cout << "This is a while loop" << std::endl;
        x++;
    }

    std::cout << "x---x---x---x---x---x---x---x---x---x---x" << std::endl;

    //METHOD_2
    int y = 0;
    do
    {
        std::cout << "This is a do while loop" << std::endl; //This will run atleast one time even if the condition is false.
        y++;
    } while (y < 5);
    
    std::cin.get();
}