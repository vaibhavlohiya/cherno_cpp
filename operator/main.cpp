#include <iostream>

struct Vec2
{
    float x, y;

    Vec2(float x, float y)
    : x(x), y(x) {}

    Vec2 add(const Vec2& other) const
    {
        return Vec2(x + other.x, y + other.y);
    }

    // + operator 
    Vec2 operator+(const Vec2& other) const
    {
        return add(other);
    }

    Vec2 multiply(const Vec2& other) const
    {
        return Vec2(x * other.x, y * other.y);
    }

    // * operator
    Vec2 operator*(const Vec2& other) const
    {
        return multiply(other);
    }

    // == operator
    bool operator==(const Vec2& other) const
    {
        return x == other.x && y == other.y;
    }

    // != operator
    bool operator!=(const Vec2& other) const
    {
        return !(*this == other);
    }

};

std::ostream& operator<<(std::ostream& stream, const Vec2& other)
{
    stream << other.x << ", " << other.y;
    return stream;
}

int main()
{
    Vec2 position(0.6f, 4.1f);
    Vec2 speed(1.1f, 7.2f);
    Vec2 powerup(3.2f, 8.3f);

    Vec2 result1 = position.add(speed.multiply(powerup));
    Vec2 result2 = position + speed * powerup;

    std::cout << result2 << std::endl;

    std::cin.get();
}