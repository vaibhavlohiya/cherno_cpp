// Move Semantics in C++

/*

A good ways to understand std::move() is that you are basically saying 
"I don't need the object that I am passing anymore. I am allowing someone 
to steal from it."

*/

// You want to use std::move when you want to convert an object to be a 'temporary'

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
        printf("Moved by move constructor\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Size = 0;
        other.m_Data = nullptr;

    }

    String& operator=(String&& other) //noexcept // Move assignment operator.
    {
        printf("Moved by move assignment operator\n");

        if (this != &other)  // if the other object is different then the current object then we move !!
        {
            delete[] m_Data;  // we need to delete the current data to avoid memory leak

            m_Size = other.m_Size;
            m_Data = other.m_Data;

            other.m_Size = 0;
            other.m_Data = nullptr;
        }

        return *this;        // if the above IF statement is false then we return the current object.
    }

    void Print()
    {
        for (uint32_t i = 0; i < m_Size; i++)
            printf("%c", m_Data[i]);
        
        printf("\n");
    }

    ~String()
    {
        printf("Destroyed\n");
        delete m_Data;
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

    /*

    String hello = "hello";
    String dest = (String&&) hello; // to explicitly use the move constructor we have to cast it into that
    String dest((String&&) hello);  // we can also type it like this.
    String dest(std::move(hello));  // or like this which is much better
    String dest = std::move(hello); // or like this (C++ is your oyster)

    */



    String orange = "Orange";
    String dest;// = std::move(orange);      // This is the move constructor .

    std::cout << "Orange : ";
    orange.Print();
    std::cout << "Dest: ";
    dest.Print();

    dest = std::move(orange);            // This is the move assignment operator.

    std::cout << "Orange: ";
    orange.Print();
    std::cout << "Dest: ";
    dest.Print();

    // MY PROGRAM IS CRASHING AND I DONT KNOW WHY !!!

    std::cin.get();
}