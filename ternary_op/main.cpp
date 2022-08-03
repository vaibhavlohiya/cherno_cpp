#include <iostream>

static int s_level = 10;
static int s_speed = 2;

int main()
{   
    // Two ways to use conditional assignments

    if (s_level > 5) // 1
        s_speed = 10;
    else 
        s_speed = 0;

    s_speed = s_level > 5 ? 10 : 0; // 2
    s_speed = s_level > 5 ? s_level > 10 ? 15 : 10 : 5;
    s_speed = s_level > 5 && s_level < 100 ? s_level > 10 ? 15 : 10 : 5;

    std::string rank = s_level > 5 ? "Master" : "Rookie"; // 2

    std::string otherRank; // 1
    if (s_speed > 5)
        otherRank = "Master";
    else 
        otherRank = "Rookie";

    std::cout << s_speed << std::endl;
    std::cout << rank << std::endl;

    std::cin.get();
}