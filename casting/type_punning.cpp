#include <iostream>

struct Entity
{
    int x, y;

    int* positions()
    {
        return &x;
    }
};

int main()
{

    int b = 50;
    double value0 = (double)b; // Implicit Conversion

    //std::cout << value0 << std::endl;

    int a = 60;
    double value = *(double*)&a; // Explicit Conversion

    //std::cout << value << std::endl;

    Entity e = {5, 6};

    int* position = (int*)&e;

    // just by getting the memory location of x we can make a pointer to access the data.
    int* pos = e.positions();
    std::cout << pos[0] << pos[1] << std::endl;

    // All three of this crazy code is valid and means the same thing!!
    int y_pos_4 = *(int*)((char*)&e + 4);
    int y_pos_2 = *(int*)((short int*)&e + 2);
    int y_pos_1 = *(int*)((int*)&e + 1);

    std::cout << "y_pos: " << y_pos_4 << std::endl;

    std::cout << position[0] << ", " << position[1] << std::endl;

    std::cin.get();
}