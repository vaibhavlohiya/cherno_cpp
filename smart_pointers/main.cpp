// Smart pointers in C++

#include <iostream>
#include <memory>

class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity" << std::endl;
    }

    ~Entity()
    {
        std::cout << "Destroyed Entity" << std::endl;
    }

    void Print() {}
};

int main()
{   
    {
        std::shared_ptr<Entity> e0;

        {
            // unique pointer

            //std::unique_ptr<Entity> entity(new Entity()); // calling explicitly
            std::unique_ptr<Entity> entity = std::make_unique<Entity>(); // more safer way  

            // shared pointer

            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();  // you can copy a shared pointer .

            // weak pointer
            
            std::weak_ptr<Entity> weakEntity = sharedEntity; // a weak pointer is just like a shared pointer except it does not increases the refrence count.

            e0 = sharedEntity; // shared pointers increases a reference count everytime it gets copied.
        }
    }
    std::cin.get();
}
