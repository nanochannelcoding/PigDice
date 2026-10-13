#ifndef PIGDICE_PDGAME_H
#define PIGDICE_PDGAME_H
#include "Turn.h"

class PDGame {
private:
    Turn m_myTurn;
    bool m_gameOver;
    int m_gameScore;
public:
    PDGame();
    int getGameScore(); // 1
private:
    void displayRules();
    void playGame();
};

#endif //PIGDICE_PDGAME_H