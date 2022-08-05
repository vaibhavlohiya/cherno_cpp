// Lifetime of a heap object can be changed by making a wrapper pointer.

#include <iostream>

class Entity 
{
public:
    Entity() // constructor 
    {
        std::cout << "Created Entity" << std::endl;
    }
 
    ~Entity() // destructor
    {
        std::cout << "Destroyed Entity" << std::endl;
    }
};

class scopedPtr // A wrapper pointer for automatically free the memory after heap allocation.
{
private:
    Entity* m_Ptr;
public:
    scopedPtr(Entity* ptr) : m_Ptr(ptr) {}

    ~scopedPtr()
    {
        delete m_Ptr;
    }
};

int main()
{
    {
        scopedPtr e = new Entity(); // by doing this the heap allocated memory gets deleted when it is out of scope.
    }
    std::cin.get();
}