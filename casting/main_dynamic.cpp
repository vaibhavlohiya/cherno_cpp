// Dynamic Casting in C++

#include <iostream>

class Entity
{
public:
    Entity() { std::cout << "It is an Entity" << std::endl; }
    virtual void Hello() { }
};

class Player : public Entity
{
public:
    Player() { std::cout << "It is a Player" << std::endl; }
};

class Enemy : public Entity
{
public:
    Enemy() { std::cout << "It is an Enemy" << std::endl; }
};

int main()
{
    Entity* E = new Entity();
    Player* P = new Player();
    Enemy* En = new Enemy();

    std::cout << "---------------------------" << std::endl;

    Entity* ActuallyPlayer = new Player();
    Entity* ActuallyEnemy = new Enemy();

    std::cout << "---------------------------" << std::endl;

    Player* p0 = dynamic_cast<Player*>(ActuallyEnemy);    
    std::cout << "p0 = " << p0 << std::endl;
    Enemy* e0 = dynamic_cast<Enemy*>(ActuallyPlayer);
    std::cout << "e0 = " << e0 << std::endl;

    std::cout << "---------------------------" << std::endl;

    Player* p1 = dynamic_cast<Player*>(ActuallyPlayer);    
    std::cout << "p1 = " << p1 << std::endl;
    Enemy* e1 = dynamic_cast<Enemy*>(ActuallyEnemy);
    std::cout << "e1 = " << e1 << std::endl;

    std::cout << "---------------------------" << std::endl;

    std::cout << sizeof(Entity) << std::endl;
    std::cout << sizeof(Player) << std::endl;
    std::cout << sizeof(Enemy) << std::endl;

    std::cin.get();
}