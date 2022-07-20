#include<iostream>

struct Entity
{  
    int x, y;

    static void Print() // A static method cannot access non static variables.
    {
        std::cout << x << ", " << y << std::endl;
    }
};

static void Print(Entity E) 
{
    std::cout << E.x << ", " << E.y << std::endl;
}

int Entity::x;
int Entity::y;

int main()
{
    Entity::x = 2;
    Entity::y = 3;

    Entity::x = 6;
    Entity::y = 9; 

    // A static method can be called without a class instance as if it is in a namespace.

    Entity::Print();
    Entity::Print();

    std::cin.get();
}