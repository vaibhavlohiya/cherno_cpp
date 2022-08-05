// Vector library in C++

#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

void Function(const std::vector<Vertex>& vertices) // always pass it by reference to avoid copying.
{
    // body of the function
}

int main()
{
    std::vector<Vertex> vertices;
    vertices.push_back({1, 2, 3}); // adding something to the array vertices
    vertices.push_back({4, 5, 6});

    for (int i = 0; i < vertices.size(); i++)
        std::cout << vertices[i] << std::endl;

    for (Vertex& v : vertices) // another way to iterate the array vertices.
        std::cout << v << std::endl;

    vertices.clear(); // clearing vertices.

    vertices.erase(vertices.begin() + 1); // for erasing a particular set in this ({4, 5, 6})

    std::cin.get();
}