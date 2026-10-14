#include "PDGame.h"
#include <iostream>

PDGame::PDGame() {
    bool m_gameOver = false;
    int m_gameScore = 0;
    m_myTurn.setParentGame(this); // 7
    displayRules();
    playGame();
}
int PDGame::getGameScore() { // 2
    return m_gameScore;
}
void PDGame::displayRules() {
    std::cout << "Let's Play PIG Dice!" << std::endl;
    std::cout << std::endl;
    std::cout << "* See how many turns it takes you to get to 20 points." << std::endl;
    std::cout << "* Turn ends when you hold or roll a 1." << std::endl;
    std::cout << "* If you roll a 1, you lose all points for the turn." << std::endl;
    std::cout << "* If you hold, you bank all points for the turn to the game score." << std::endl;
    std::cout << std::endl;
}
void PDGame::playGame() {
    while (m_gameOver == false) {
        m_myTurn.takeTurn();
        m_gameScore+=m_myTurn.getScoreThisTurn();
        if (m_gameScore >= 20) {
            m_gameOver= true;
        }
        else {
            m_myTurn.resetTurnOver();
            m_myTurn.resetScoreThisTurn();
            m_myTurn.getTurnCount == m_myTurn.getTurnCount + 1;
        }
    }
}
