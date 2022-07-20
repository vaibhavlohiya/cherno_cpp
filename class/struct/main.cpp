#include<iostream>

#define LOG(x) std::cout << x << std::endl

struct Player // Plain old data (POD)
{
    int x, y;
    int speed;

    void Move(int xa, int ya) // Move function is inside the class, where it is called a method. 
    {
        x += xa * speed;
        y += ya * speed;

    }
};

struct vec2
{
    float x;
    float y;
};

// Don't use structures for inheritance.

int main()
{
    Player player; // Instanciating a player object.

    player.x = 6; 

    player.Move(1, -1); 

    std::cin.get();
}