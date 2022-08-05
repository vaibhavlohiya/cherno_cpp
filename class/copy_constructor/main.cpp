// copying and copy constructor in C++

// JHAANT SAMAJH NHI AA RHA 

#include <iostream>
#include <cstring>

struct Vec2
{
    float x, y;
};

class string
{
private:
    unsigned int m_size;
    char* m_buffer;
public:
    string(const char* str) 
        : m_size(strlen(str)), m_buffer(new char[m_size])
    { 
        memcpy(m_buffer, str, m_size); 
    }

};

std::ostream

int main()
{
    // stack allocation

    Vec2 v = {2, 3}; // even after we change the value of x, y on u this will remain intact .
    Vec2 u = v; 

    u.x = 9;
    u.y = 6;

    // heap allocation

    Vec2* a = new Vec2();
    Vec2* b = a; // in this we are actually copying the pointer pointing to memory address. so we have 2 pointers pointing to the same memory.

    b->x = 7;

    std::cout << a->x << std::endl; 

    std::cin.get();
}