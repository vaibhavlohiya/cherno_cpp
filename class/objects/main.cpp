// Instantiating objects in C++

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

int* CreateArray() // This is wrong because this function returns array and the array variable cease to exist outside the function's scope.
{
    int array[50];
    return array;
}

void CreateArray(int* array)
{
    // fill the array
}

int main()
{
    int array[50];
    CreateArray(array);

    int* a = CreateArray();

    // Instantiating objects on the stack.

    // The objects that are created on the stack gets destroyed once the scope of the function is ended.

    Entity entity_1; // Calling the default constructor on the stack
    std::cout << entity_1.GetName() << std::endl;

    Entity entity_2("Vaibhav"); // Calling the constructor with an argument on the stack
    //Entity entity_2 = Entity("Vaibhav"); // You can also write it like this 
    std::cout << entity_2.GetName() << std::endl;

    // Instantiating objects on the heap.

    // The objects on the heap remains in the code unless you manually delete them.

    Entity* e;
    {
        Entity* entity_3 = new Entity("Vaibhav");
        e = entity_3;
        std::cout << entity_3->GetName() << std::endl;
    }

    delete e;

    std::cin.get();
}