// Member Initializer list in C++

#include <iostream>

class Example
{
public:
    Example()
    {
        std::cout << "Created Entity" << std::endl;
    }

    Example(int x)
    {
        std::cout << "Created Entity with " << x << "!" << std::endl;
    }
};

class Entity
{
private:
    std::string m_Name; // Always initialise the member variables in methods in order.
    int m_Score;
    Example m_Example;
public:

    // Two ways to define a simple method in a class.

    Entity() //: m_Example(2) 
    {
        m_Name = "Unknown"; // 1
        m_Score = 5;
        //m_Example = Example(2);
    }

    Entity(const std::string& name, int score) : m_Name(name), m_Score(score) {} // 2

    const std::string& GetName() const { return m_Name; }
};

int main()
{
    Entity e0;
    std::cout << e0.GetName() << std::endl;
    
    Entity e1("Vaibhav", 10);
    std::cout << e1.GetName() << std::endl;

    std::cin.get();
}