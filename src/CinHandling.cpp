#include"CinHandling.hpp"

#include <limits>
#include <iostream>
void clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}