// If you want to override a functions you might want to use vitual functions.


#include <iostream>
#include <string>

class Printable
{
public:
    virtual std::string GetClassName() = 0; // must be defined in other classes. 
};

// Entity class which will have a vitual function called GetName.
class Entity : public Printable
{
public:
    virtual std::string GetName() { return "Entity"; } // Virtual functions uses dynamic dispatch (V-table).
    std::string GetClassName() override { return "Entity"; }

};

// Player class which whill inherit the public part of class Entity.
class Player : public Entity
{   
private:
    std::string m_Name;
public:
    Player(const std::string& name)
        : m_Name(name) {}
    
    std::string GetName() override { return m_Name; }
    std::string GetClassName() override { return "Player"; }

};

void printName(Entity* entity)
{
    std::cout << entity->GetName() << std::endl;
}

void Print(Printable* obj)
{
    std::cout << obj->GetClassName() << std::endl;
}

int main()
{
    Entity* e = new Entity(); // Creating an instance of the class Entity.
    //std::cout << e->GetName() << std::endl;

    Player* p = new Player("Cherno"); // Creating an insance of class Player.
    //std::cout << p->GetName() << std::endl;

    //printName(p); // p is a pointer to a player type.

    Print(e); // Print for Entity.
    Print(p); // Print for Player.

    std::cin.get();
}