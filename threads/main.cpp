// Multi-threading in C++ 

// Use command : "g++ main.cpp -o main -pthread"

#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork()
{
    while (!s_Finished)
        std::cout << "Working..." << std::endl;
}

int main()
{
    std::thread worker(DoWork);
    std::cin.get();

    s_Finished = true;

    worker.join();
    std::cout << "The work is finished" << std::endl;

    std::cin.get();
}