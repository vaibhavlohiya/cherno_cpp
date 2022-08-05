// Arrow operator in C++

#include <iostream>

class Entity
{
public:
    void Print() { std::cout << "Hello" << std::endl; }
};

class Scopedptr
{
private:
    Entity* m_Obj;
public:
    Scopedptr(Entity* entity)
        : m_Obj(entity)
    {}

    ~Scopedptr()
    {
        delete m_Obj;
    }

    Entity* operator->()
    {
        return m_Obj;
    }
    
};

struct Vector3
{
    float x, y, z;
};

int main()
{
    Entity e;
    e.Print();

    Entity* ptr = &e;

    // code on line 19 and 20 mean the same thing.
    (*ptr).Print();
    ptr->Print();

    Scopedptr entity = new Entity();
    entity->Print();

    // to find the offset of x,y and z in memory

    int offset = (int)&((Vector3*)0)->y; // C++ makes my brain hurt
    std::cout << offset << std::endl;


    std::cin.get();
}