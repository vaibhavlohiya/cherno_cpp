//  Visiblity in C++

#include <iostream>
#include <string>

class Entity
{
// Under protected you can access the protected variables from any subclasses but not from the main function.
protected:
    int X;
public:
    Entity()
    {
        X = 2;
    }
    virtual void Print() = 0; // Pure virtual function.
};

class Player : public Entity
{
protected:
    int Y;
public:
    Player()    
    {
        Y = 5;
    }
    void Print() override { std::cout << X + Y << std::endl; } 
};

void Print_num(Entity* e)
{
    e->Print();
}

int main()
{   
    Player* P = new Player();
    Print_num(P);

    std::cin.get();
}