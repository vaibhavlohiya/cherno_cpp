// Move Semantics in C++

/*

Here, we are addressing the object being copied twice to use it properly which is 
not the best thing performance wise because memory is allocated on the heap twice and 
which means more instructons given and hence less performance optimization.

However this problem can be solved by using the move semantics method in which instead 
of copying the object we move the object from one function to another to increase 
performance and this is done by the help of rvalue reference.

*/

#include <iostream>
#include <cstring>

class String
{
public: 

    String() = default;
    String(const char* string)
    {
        printf("Created\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    String(const String& other)    // Copy Constructor (Deep Copy)
    {
        printf("Copied\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    String(String&& other) noexcept     // This is an rvalue reference. (Shallow Copy)
    {
        printf("Moved\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;
        memcpy(m_Data, other.m_Data, m_Size);

        other.m_Size = 0;
        other.m_Data = nullptr;

    }

    void Print()
    {
        for (uint32_t i = 0; i < m_Size; i++)
            printf("%c", m_Data[i]);
        
        printf("\n");
    }

    ~String()
    {
        delete m_Data;

        printf("Destroyed\n");
    }

private:
    char* m_Data;
    uint32_t m_Size;
};

class Entity
{
public:

    Entity(const String& name)
        : m_name(name)
    {}

    Entity(String&& name)  // rvalue reference 
        : m_name(std::move(name))            // To use the moved constructor you have to explicitly cast it as moved.
    {}

    void PrintName()
    {
        m_name.Print();
    }

private:
    String m_name;
};


int main()
{
    Entity entity(String("Vaibhav"));

    entity.PrintName();

    std::cin.get();
}