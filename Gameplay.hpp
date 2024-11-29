#include "Checkers.hpp"
#include "CinHandling.hpp"
void gameplay(Board &b, bool &continuegame) {
    int moveFrom, moveTo;

    while (continuegame) {
        // Draw the board and prompt for X's move
        b.drawBoard();
        std::cout << "\nNow X plays\n";

        while (!(std::cin >> moveFrom >> moveTo)) {
            std::cout << "You have to use integers: ";
            clearInput();
        }
        std::cout << "\n";

        // Make X's move and check for win
        b.makeMove(true, moveFrom, moveTo);
        if (b.checkForWin(true)) {
            std::cout << "X WINS!!!\n";
            continuegame = false;
            break;
        }

        // Draw the board and prompt for O's move
        b.drawBoard();
        std::cout << "\nNow O plays\n";

        while (!(std::cin >> moveFrom >> moveTo)) {
            std::cout << "You have to use integers: ";
            clearInput();
        }
        std::cout << "\n";

        // Make O's move and check for win
        b.makeMove(false, moveFrom, moveTo);
        if (b.checkForWin(false)) {
            std::cout << "O WINS!!!\n";
            continuegame = false;
            break;
        }
    }

    // Prompt for a replay
    std::cout << "Want to play again?[yes=1/no=0]\n";
    while (!(std::cin >> continuegame)) {
        std::cout << "You have to use integers: ";
        clearInput();
    }
}