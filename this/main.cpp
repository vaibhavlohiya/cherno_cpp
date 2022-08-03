#include <iostream>

void PrintEntity(Entity* e);

class Entity
{
public:
    int x, y;

    Entity(int x, int y)
    {
        // First method
        Entity* e = this;

        e->x = x;
        e->y = y;

        // Second method
        this->x = x;
        this->y = y;

        PrintEntity(this); // to get the current instance of the entity class.

    }

    int GetX() const
    {
        const Entity* e = this;

        return x;
    }
};

void PrintEntity(Entity* e)
{
    // body of the function
}


int main()
{
    std::cin.get();
}