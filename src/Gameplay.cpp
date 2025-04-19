#include "Gameplay.hpp"
#include "CinHandling.hpp"

#include<iostream>

void gameplay(Board &b, bool &continuegame)
{
    int moveFrom, moveTo;

    while (continuegame)
    {
        b.drawBoard();
        std::cout << "\nNow X plays\n";

        while (!(std::cin >> moveFrom >> moveTo))
        {
            std::cout << "You have to use integers: ";
            clearInput();
        }
        std::cout << "\n";

        b.makeMove(true, moveFrom, moveTo);
        if (b.checkForWin(true))
        {
            std::cout << "X WINS!!!\n";
            continuegame = false;
            break;
        }

        b.drawBoard();
        std::cout << "\nNow O plays\n";

        while (!(std::cin >> moveFrom >> moveTo))
        {
            std::cout << "You have to use integers: ";
            clearInput();
        }
        std::cout << "\n";

        b.makeMove(false, moveFrom, moveTo);
        if (b.checkForWin(false))
        {
            std::cout << "O WINS!!!\n";
            continuegame = false;
            break;
        }
    }

    std::cout << "Want to play again?[yes=1/no=0]\n";
    while (!(std::cin >> continuegame))
    {
        std::cout << "You have to use integers: ";
        clearInput();
    }
}