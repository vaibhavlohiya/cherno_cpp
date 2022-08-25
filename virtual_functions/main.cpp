// If you want to override a functions you might want to use virtual functions.


#include <iostream>
#include <string>

// Entity class which will have a vitual function called GetName.
class Entity
{
public:
    virtual std::string GetName() { return "Entity"; } // Virtual functions uses dynamic dispatch (V-table).
    
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
};

void printName(Entity* entity)
{
    std::cout << entity->GetName() << std::endl;
}

int main()
{
    Entity* e = new Entity(); // Creating an instance of the class Entity.
    std::cout<< e->GetName() << std::endl;

    printName(e);

    Player* p = new Player("Cherno"); // Creating an insance of class Player.
    std::cout << p->GetName() << std::endl;

    printName(p); // p is a pointer to a player type.

    std::cin.get();
}