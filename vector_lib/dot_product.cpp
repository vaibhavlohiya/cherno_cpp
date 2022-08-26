// Vector dot product in C++

#include <iostream>

class Vec
{
private:
    float x, y, z;
public: 
    Vec(float x, float y, float z) // constructor
        : x(x), y(y), z(z)
    {
        //std::cout << "A vector is created " << std::endl;
    }

    ~Vec() // destructor
    {
        //std::cout << "A vector is deleted " << std::endl;
    }

    float* arr() { return &x; }
};

float Vec_dot(Vec& v1, Vec& v2)
{
    float* pos_1 = v1.arr(); // array of vector 1
    float* pos_2 = v2.arr(); // array of vector 2

    return pos_1[0]*pos_2[0] + pos_1[1]*pos_2[1] + pos_1[2]*pos_2[2]; // vector dot product

    
}

//float Vec_dot(Vec& v1, Vec& v2) { return (v1.x)*(v2.x) + (v1.y)*(v2.y) + (v1.z)*(v2.z); }

int main()
{
    Vec v1(1, 2, 3);
    Vec v2(4, 5, 6);

    //float* position_1 = v1.v();
    //float* position_2 = v2.v();

    //std::cout << position_1[0] << ", " << position_1[1] << ", " << position_1[2] << std::endl;
    //std::cout << position_2[0] << ", " << position_2[1] << ", " << position_2[2] << std::endl;

    std::cout << "The dot product of the two vectors is: " << Vec_dot(v1, v2) << std::endl;

    std::cin.get();
}