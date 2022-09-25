// L_VALUES and R_VALUES in C++

#include <iostream>

int& GetValue() // this '&' is lvalue reference
{
    static int value = 10;
    return 10;
}

int SetValue(int& a) // this won't work on function "SaveValue(10)". To work for both ways we need to put const on 'a'
{
    return a;
}

std::string GetName(const std::string& name) // This would take both rvalues and lvalues.
{
    return name;
}

std::string GetName(std::string&& name) // This is an rvalue reference '&&' this would only accept temp values.
{
    return name;
}


int main()
{
    int i = 10;  // Here i is an lvalue and 10 is an rvalue

    int a = i;  // this expression is possible where both are lvalues, but with rvalue it is not.

    GetValue() = 5;

    SetValue(i);  // Calling the function with an lvalue.
    SetValue(10); // Calling the function with a rvalue.

    // NOTE: You cannot take an lvalue reference from an rvalue, you can only take it from an lvalue.

    // Since you can't take an lvalue reference from a rvalue but after making the lvalue const you can!!

    int& b = 5;       // This is not valid
    const int& b = 5; // But this is

    std::string first_name = "Vaibhav";
    std::string last_name = "Lohiya";

    std::string full_name = first_name + last_name;

    GetName(full_name);               // This would work fine since it is an lvalue.
    GetName(first_name + last_name);  // For this to work we need to put const in the expression parameter. 


}