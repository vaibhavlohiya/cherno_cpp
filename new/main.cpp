// new keyword in C++

// The purpose of new is to allocate memory specifically on the heap. It is an operator.

#include <iostream>

using String = std::string;

class Entity
{
private:
    String m_name;
public:
    Entity() : m_name("Unknown") {}
    Entity(const String& name) : m_name(name) {}

    const String& GetName() const { return m_name; }
};

int main()
{
    int a = 4;

    // using new keyword to allocate simple variables on the heap

    int* b = new int; // 4 bytes of memory allocated on the heap
    int* c = new int[30]; // 30 times 4 = 120 bytes on memory allocated on the heap

    Entity* e = new Entity();
    Entity* e = new Entity[30]; // 30 entity objects are created on the heap and stored side by side like a stack.

    // delete frees the memory and also calls the destructor.

    delete b; 
    delete[] c;
    delete e;
    delete[] e;

    std::cin.get();
}