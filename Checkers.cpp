#include <iostream>
#include "Gameplay.hpp"

int main()
{
    while (true)
    {
        Board b;
        b.setupBoard();
        int moveFrom;
        int moveTo;
        bool continuegame = true;
        while (continuegame)
        {
            gameplay(b, continuegame);
        }
    }
    return 0;
}