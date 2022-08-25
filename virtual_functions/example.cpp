#include <iostream>

class Employee
{
public:
    virtual void Raise_Salary() { std::cout << "Raising salary by 5 %" << std::endl; }

    void Promotion() { std::cout << "Promoting him/her" << std::endl; }
};

class Engineer : public Employee
{
public:
    void Raise_Salary() override { std::cout << "Raising salary by 30 %" << std::endl; }
};

int main()
{
    Employee* emp = new Employee();
    emp->Raise_Salary();
    emp->Promotion();

    Engineer* eng = new Engineer();
    eng->Raise_Salary();
    eng->Promotion();

    Employee* abc = new Engineer();  // Up-casting method
    abc->Raise_Salary();
    abc->Promotion();

    std::cin.get();
}