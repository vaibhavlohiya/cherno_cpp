#include <iostream>
#include <vector>

struct ParticleCoordinates
{
    float X, Y, Z;

    /*ParticleCoordinates(float X, float Y, float Z)
        : X(X), Y(Y), Z(Z)
    {}*/
};


std::ostream& operator<<(std::ostream& stream, const ParticleCoordinates& coord) // reading (Output)
{
    stream << coord.X << ", " << coord.Y << ", " << coord.Z << std::endl;
    return stream;
}

std::istream& operator>>(std::istream& stream, ParticleCoordinates& coord) // writing (Input)
{
    stream >> coord.X >> coord.Y >> coord.Z;
    return stream;
}


void Particle_Track(ParticleCoordinates& coord)
{
    std::vector<ParticleCoordinates> Particle;
    std::cin >> coord;

    Particle.push_back({coord.X, coord.Y, coord.Z});
    std::cout << Particle[0] << std::endl;
}

/*void Particle_Track(float X, float Y, float Z)
{
    std::vector<ParticleCoordinates> Particle;
    Particle.emplace_back(X, Y, Z);

    std::cout << Particle[0] << std::endl;
}*/

int main()
{
    ParticleCoordinates coord;
    Particle_Track(coord);
    std::cin.get();
}