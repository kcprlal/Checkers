#include <limits>
void clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}