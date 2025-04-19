#pragma once

class Board {
public:
    ~Board();
    void setupBoard();
    void drawBoard();
    void makeMove(bool xplays, int moveFrom, int moveTo);
    bool checkForWin(bool xplays);

private:
    bool checkIfLegal(int state, int moveFrom, int moveTo, bool onLeft, bool onRight);
    char field[64];
    int Xpawns;
    int Opawns;
    bool onSiteLeft;
    bool onSiteRight;
    bool onSiteLeftTake;
    bool onSiteRightTake;
};

