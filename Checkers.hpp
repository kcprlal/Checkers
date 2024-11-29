#include <iostream>

class Board
{
public:
    Board::~Board()
{
    std::cout << "\nWORKING\n";
}

void Board::setupBoard()
{

    Xpawns = 12;
    Opawns = 12;
    for (int k = 0; k < 64; ++k)
    {
        field[k] = ' ';
    }
    for (int i = 0; i < 8; i += 2)
    {
        field[i] = 'x';
        field[9 + i] = 'x';
        field[16 + i] = 'x';
    }
    for (int i = 0; i < 8; i += 2)
    {
        field[6 * 8 + i] = 'o';
        field[9 + i + 6 * 8] = 'o';
        field[6 * 7 - 1 + i] = 'o';
    }
    // Just to test
    /*field[46] = 'X';
    field[39] = 'o';
    field[37] = 'o';
    /*field[34] = 'o';
    field[36] = 'o';*/
}

void Board::drawBoard()
{
    std::cout << "     #0  #1  #2  #3  #4  #5  #6  #7\n";
    for (int i = 0; i < 8; i++)
    {
        std::cout << '#' << i * 8;
        if (i == 0 || i == 1)
            std::cout << ' ';
        std::cout << " | ";
        for (int j = 0; j < 8; j++)
        {
            std::cout << field[i * 8 + j] << " | ";
        }
        std::cout << "\n";
    }
}

bool Board::checkIfLegal(int state, int moveFrom, int moveTo, bool onLeft, bool onRight)
{
    if (state == 0)
    {
        if (onLeft)
        {
            if (field[moveFrom] == 'x' && field[moveTo] == ' ' && moveTo - moveFrom == 9)
                return true;
            else
                return false;
        }
        else if (onRight)
        {
            if (field[moveFrom] == 'x' && field[moveTo] == ' ' && (moveTo - moveFrom == 7))
                return true;
            else
                return false;
        }
        else
        {
            if (field[moveFrom] == 'x' && field[moveTo] == ' ' && (moveTo - moveFrom == 7 || moveTo - moveFrom == 9))
                return true;
        }
    }

    else if (state == 1)
    {
        if (onLeft)
        {
            if (field[moveTo] == ' ' && moveTo - moveFrom == 18 && (field[moveTo - 9] == 'o' || field[moveTo - 9] == 'O'))
            {
                field[moveTo - 9] = ' ';
                return true;
            }
            else
                return false;
        }

        if (onRight)
        {
            if (field[moveTo] == ' ' && moveTo - moveFrom == 14 && (field[moveTo - 7] == 'o' || field[moveTo - 7] == 'O'))
            {
                field[moveTo - 7] = ' ';
                return true;
            }
            else
                return false;
        }

        else
        {
            if (field[moveTo] == ' ' && moveTo - moveFrom == 14 && (field[moveTo - 7] == 'o' || field[moveTo - 7] == 'O'))
            {
                field[moveTo - 7] = ' ';
                return true;
            }
            else if (field[moveTo] == ' ' && moveTo - moveFrom == 18 && (field[moveTo - 9] == 'o' || field[moveTo - 9] == 'O'))
            {
                field[moveTo - 9] = ' ';
                return true;
            }
        }
    }

    else if (state == 2)
    {
        if (onLeft)
        {
            if (field[moveFrom] == 'o' && field[moveTo] == ' ' && moveFrom - moveTo == 7)
                return true;
            else
                return false;
        }

        if (onRight)
        {
            if (field[moveFrom] == 'o' && field[moveTo] == ' ' && moveFrom - moveTo == 9)
                return true;
            else
                return false;
        }

        else
        {
            if (field[moveFrom] == 'o' && field[moveTo] == ' ' && (moveFrom - moveTo == 7 || moveFrom - moveTo == 9))
                return true;
        }
    }

    else if (state == 3)
    {
        if (onLeft)
        {
            if (field[moveTo] == ' ' && moveFrom - moveTo == 14 && (field[moveTo + 7] == 'x' || field[moveTo + 7] == 'X'))
            {
                field[moveTo + 7] = ' ';
                return true;
            }
            else
                return false;
        }

        if (onRight)
        {
            if (field[moveTo] == ' ' && moveFrom - moveTo == 18 && (field[moveTo + 9] == 'x' || field[moveTo + 9] == 'X'))
            {
                field[moveTo + 9] = ' ';
                return true;
            }
            else
                return false;
        }

        else
        {
            if (field[moveTo] == ' ' && moveFrom - moveTo == 14 && (field[moveTo + 7] == 'x' || field[moveTo + 7] == 'X'))
            {
                field[moveTo + 7] = ' ';
                return true;
            }
            else if (field[moveTo] == ' ' && moveFrom - moveTo == 18 && (field[moveTo + 9] == 'x' || field[moveTo + 9] == 'X'))
            {
                field[moveTo + 9] = ' ';
                return true;
            }
        }
    }
    else if (state == 4)
    {
        if (onLeft)
        {
            if (field[moveFrom] == 'X' && field[moveTo] == ' ' && (moveTo - moveFrom == 9 || moveFrom - moveTo == 7))
                return true;
            else
                return false;
        }
        else if (onRight)
        {
            if (field[moveFrom] == 'X' && field[moveTo] == ' ' && (moveTo - moveFrom == 7 || moveFrom - moveTo == 9))
                return true;
            else
                return false;
        }
        else
        {
            if (field[moveFrom] == 'X' && field[moveTo] == ' ' && (moveTo - moveFrom == 7 || moveTo - moveFrom == 9 || moveFrom - moveTo == 7 || moveFrom - moveTo == 9))
                return true;
        }
    }
    else if (state == 5)
    {
        if (onLeft)
        {
            if (field[moveTo] == ' ' && moveTo - moveFrom == 18 && (field[moveTo - 9] == 'o' && field[moveTo - 9] == 'O'))
            {
                field[moveTo - 9] = ' ';
                return true;
            }
            else if (field[moveTo] == ' ' && moveFrom - moveTo == 14 && (field[moveTo + 7] == 'o' || field[moveTo + 7] == 'O'))
            {
                field[moveTo + 7] = ' ';
                return true;
            }
            else
                return false;
        }

        if (onRight)
        {
            if (field[moveTo] == ' ' && moveTo - moveFrom == 14 && (field[moveTo - 7] == 'o' && field[moveTo - 7] == 'O'))
            {
                field[moveTo - 7] = ' ';
                return true;
            }
            else if (field[moveTo] == ' ' && moveFrom - moveTo == 18 && (field[moveTo + 9] == 'o' || field[moveTo + 9] == 'O'))
            {
                field[moveTo + 9] = ' ';
                return true;
            }
            else
                return false;
        }

        else
        {
            if (field[moveTo] == ' ' && moveTo - moveFrom == 14 && (field[moveTo - 7] == 'o' || field[moveTo - 7] == 'O'))
            {
                field[moveTo - 7] = ' ';
                return true;
            }
            else if (field[moveTo] == ' ' && moveTo - moveFrom == 18 && (field[moveTo - 9] == 'o' || field[moveTo - 9] == 'O'))
            {
                field[moveTo - 9] = ' ';
                return true;
            }
            else if (field[moveTo] == ' ' && moveFrom - moveTo == 18 && (field[moveTo + 9] == 'o' || field[moveTo + 9] == 'O'))
            {
                field[moveTo + 9] = ' ';
                return true;
            }
            else if (field[moveTo] == ' ' && moveFrom - moveTo == 14 && (field[moveTo + 7] == 'o' || field[moveTo + 7] == 'O'))
            {
                field[moveTo + 7] = ' ';
                return true;
            }
        }
    }
    else if (state == 6)
    {
        if (onLeft)
        {
            if (field[moveFrom] == 'O' && field[moveTo] == ' ' && (moveTo - moveFrom == 9 || moveFrom - moveTo == 7))
                return true;
            else
                return false;
        }
        else if (onRight)
        {
            if (field[moveFrom] == 'O' && field[moveTo] == ' ' && (moveTo - moveFrom == 7 || moveFrom - moveTo == 9))
                return true;
            else
                return false;
        }
        else
        {
            if (field[moveFrom] == 'O' && field[moveTo] == ' ' && (moveTo - moveFrom == 7 || moveTo - moveFrom == 9 || moveFrom - moveTo == 7 || moveFrom - moveTo == 9))
                return true;
        }
    }
    else if (state == 7)
    {
        if (onLeft)
        {
            if (field[moveTo] == ' ' && moveTo - moveFrom == 18 && (field[moveTo - 9] == 'x' && field[moveTo - 9] == 'X'))
            {
                field[moveTo - 9] = ' ';
                return true;
            }
            else if (field[moveTo] == ' ' && moveFrom - moveTo == 14 && (field[moveTo + 7] == 'x' || field[moveTo + 7] == 'X'))
            {
                field[moveTo + 7] = ' ';
                return true;
            }
            else
                return false;
        }

        if (onRight)
        {
            if (field[moveTo] == ' ' && moveTo - moveFrom == 14 && (field[moveTo - 7] == 'x' && field[moveTo - 7] == 'X'))
            {
                field[moveTo - 7] = ' ';
                return true;
            }
            else if (field[moveTo] == ' ' && moveFrom - moveTo == 18 && (field[moveTo + 9] == 'x' || field[moveTo + 9] == 'X'))
            {
                field[moveTo + 9] = ' ';
                return true;
            }
            else
                return false;
        }

        else
        {
            if (field[moveTo] == ' ' && moveTo - moveFrom == 14 && (field[moveTo - 7] == 'x' || field[moveTo - 7] == 'X'))
            {
                field[moveTo - 7] = ' ';
                return true;
            }
            else if (field[moveTo] == ' ' && moveTo - moveFrom == 18 && (field[moveTo - 9] == 'x' || field[moveTo - 9] == 'X'))
            {
                field[moveTo - 9] = ' ';
                return true;
            }
            else if (field[moveTo] == ' ' && moveFrom - moveTo == 18 && (field[moveTo + 9] == 'x' || field[moveTo + 9] == 'X'))
            {
                field[moveTo + 9] = ' ';
                return true;
            }
            else if (field[moveTo] == ' ' && moveFrom - moveTo == 14 && (field[moveTo + 7] == 'x' || field[moveTo + 7] == 'X'))
            {
                field[moveTo + 7] = ' ';
                return true;
            }
        }
    }
    return false;
}

void Board::makeMove(bool xplays, int moveFrom, int moveTo)
{
    onSiteLeft = false;
    onSiteRight = false;
    onSiteRightTake = false;
    onSiteLeftTake = false;
    if (moveFrom % 8 == 0)
    {
        onSiteLeft = true;
    }
    else if (moveFrom % 8 == 7)
    {
        onSiteRight = true;
    }
    else if (moveFrom % 8 == 6)
    {
        onSiteRightTake = true;
    }
    else if (moveFrom % 8 == 1)
    {
        onSiteLeftTake = true;
    }

    if (xplays)
    {
        if ((moveTo > 0 && moveTo < 64 && moveFrom > 0 && moveFrom < 64) && field[moveFrom] == 'x')
        {
            if (checkIfLegal(0, moveFrom, moveTo, onSiteLeft, onSiteRight))
            {
                field[moveFrom] = ' ';
                field[moveTo] = 'x';
                if (moveTo > 55)
                    field[moveTo] = 'X';
            }
            else if (checkIfLegal(1, moveFrom, moveTo, onSiteLeftTake, onSiteRightTake))
            {
                Opawns -= 1;
                field[moveFrom] = ' ';
                field[moveTo] = 'x';
                if (moveTo > 55)
                    field[moveTo] = 'X';
            }

            else
            {
                std::cout << "ILLEGAL MOVEEEE pick new fields\n";
                std::cin >> moveFrom >> moveTo;
                std::cout << '\n';
                makeMove(true, moveFrom, moveTo);
            }
        }
        else if (moveTo > 0 && moveTo < 64 && moveFrom > 0 && moveFrom < 64 && field[moveFrom] == 'X')
        {
            if (checkIfLegal(4, moveFrom, moveTo, onSiteLeft, onSiteRight))
            {
                field[moveFrom] = ' ';
                field[moveTo] = 'X';
            }
            else if (checkIfLegal(5, moveFrom, moveTo, onSiteLeftTake, onSiteRightTake))
            {
                Opawns -= 1;
                field[moveFrom] = ' ';
                field[moveTo] = 'X';
            }
            else
            {
                std::cout << "ILLEGAL MOVEEEE pick new fields\n";
                std::cin >> moveFrom >> moveTo;
                std::cout << '\n';
                makeMove(true, moveFrom, moveTo);
            }
        }
        else
        {
            std::cout << "ILLEGAL MOVEEEE pick new fields\n";
            std::cin >> moveFrom >> moveTo;
            std::cout << '\n';
            makeMove(true, moveFrom, moveTo);
        }
    }
    else
    {
        if ((moveTo > 0 && moveTo < 64 && moveFrom > 0 && moveFrom < 64) && field[moveFrom] == 'o')
        {
            if (checkIfLegal(2, moveFrom, moveTo, onSiteLeft, onSiteRight))
            {
                field[moveFrom] = ' ';
                field[moveTo] = 'o';
                if (moveTo < 8)
                    field[moveTo] = 'O';
            }
            else if (checkIfLegal(3, moveFrom, moveTo, onSiteLeftTake, onSiteRightTake))
            {
                Xpawns -= 1;
                field[moveFrom] = ' ';
                field[moveTo] = 'O';
                if (moveTo < 8)
                    field[moveTo] = 'O';
            }

            else
            {
                std::cout << "ILLEGAL MOVEEEE pick new fields\n";
                std::cin >> moveFrom >> moveTo;
                std::cout << '\n';
                makeMove(true, moveFrom, moveTo);
            }
        }
        else if (moveTo > 0 && moveTo < 64 && moveFrom > 0 && moveFrom < 64 && field[moveFrom] == 'O')
        {
            if (checkIfLegal(6, moveFrom, moveTo, onSiteLeft, onSiteRight))
            {
                field[moveFrom] = ' ';
                field[moveTo] = 'O';
            }
            else if (checkIfLegal(7, moveFrom, moveTo, onSiteLeftTake, onSiteRightTake))
            {
                Xpawns -= 1;
                field[moveFrom] = ' ';
                field[moveTo] = 'O';
            }
            else
            {
                std::cout << "ILLEGAL MOVEEEE pick new fields\n";
                std::cin >> moveFrom >> moveTo;
                std::cout << '\n';
                makeMove(true, moveFrom, moveTo);
            }
        }
        else
        {
            std::cout << "ILLEGAL MOVEEEE pick new fields\n";
            std::cin >> moveFrom >> moveTo;
            std::cout << '\n';
            makeMove(true, moveFrom, moveTo);
        }
    }
}

bool Board::checkForWin(bool xplays)
{
    if (xplays)
    {
        if (Opawns < 1)
            return true;
        else
            return false;
    }
    else
    {
        if (Xpawns < 1)
            return true;
        else
            return false;
    }
}

private:
    char field[64];
    int Xpawns;
    int Opawns;
    bool onSiteLeft;
    bool onSiteRight;
    bool onSiteLeftTake;
    bool onSiteRightTake;
};

