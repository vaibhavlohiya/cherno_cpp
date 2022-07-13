#include<iostream>

#define LOG(x) std::cout << x << std::endl

class Player
{
public:
    int x, y;
    int speed;

    void Move_method(int xa, int ya) // Move function inside the class, where it is called a method. 
    {
        x += xa * speed;
        y += ya * speed;

    }
};

void Move(Player& player, int xa, int ya) // Move function outside the class. 
{
    player.x += xa * player.speed;
    player.y += ya * player.speed;
}

int main()
{
    Player player; // Instanciating a player object.

    player.x = 6; 

    // Both functions are the same but the first one is outside and the second one is inside a class.
    Move(player, 1, -1);
    player.Move_method(1, -1); 

    std::cin.get();
}