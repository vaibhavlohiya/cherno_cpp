#include <iostream>
#include <string>

#include <cstring>

int main()
{   
    

    char name_0[] = "Vaibhav"; // const makes sure that the name is not mutable.
    name_0[2] = 'g';

    std::cout << name_0 << std::endl;
    std::cout << strlen(name_0) << std::endl;

    // types of char

    const char* name_1 = u8"Vaibhav";  // 1 byte per character (UTF-8)
    const wchar_t* name_2 = L"Vaibhav"; // 2 bytes per character
    const char16_t* name_3 = u"Vaibhav"; // 2 bytes per character (UTF-16)
    const char32_t* name_4 = U"Vaibhav"; // 4 bytes per character (UTF-32)
 
    std::cin.get();
}