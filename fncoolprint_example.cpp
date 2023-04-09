#include "fncoolprint.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    std::cout << std::endl;
    fncoolprint((char*)"Hello, world", (char*)"*", 16, 5);
    std::cout << std::endl;
    fncoolprint((char*)"Hello, world", (char*)"#", 24, 5);
    std::cout << std::endl;
    fncoolprint((char*)"Hello, world", (char*)"$", 32, 5);
    std::cout << std::endl;
    fncoolprint((char*)"Hello, world", (char*)"~", 48, 5);
    std::cout << std::endl;
    fncoolprint((char*)"Hello, world", (char*)"/", 64, 5);
    std::cout << std::endl;
}