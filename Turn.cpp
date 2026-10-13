#include <iostream>
#include "Turn.h"
#include "PDGame.h" // 8

Turn::Turn() {
    m_turnCount = 0;
    m_scoreThisTurn = 0;
    m_turnOver = false;
    m_choice = '\0';
}
void Turn::setParentGame(PDGame* parentGame) { // 6
    m_parentGame = parentGame;
}

void Turn::takeTurn() {
    std::cout << "TURN " << m_turnCount;
    std::cout << " - Game Score: " << m_parentGame->getGameScore(); // 9
    while (m_turnOver == false) {
        std::cout << "\nroll or hold? (r/h): ";
        std::cin >> m_choice;
        if (m_choice == 'r') {
            roll();
        }
        else if (m_choice == 'h') {
            std::cout << "Score banked this turn: " << m_scoreThisTurn << std::endl << std::endl;
            m_turnOver = true;
        }
        else {
            std::cout << "Please enter a valid choice." << std::endl;
        }
    }
}
int Turn::getScoreThisTurn() {
    return m_scoreThisTurn;
}
void Turn::resetTurnOver() {
    m_turnOver = false;
}
int Turn::getTurnCount() {
    return m_turnCount;
}
void Turn::resetScoreThisTurn() {
    m_scoreThisTurn = 0;
}
void Turn::roll() {
    m_myDie.roll();
    std::cout << "You rolled a " << roll << std::endl;
    if (roll == 1) {
        std::cout << "\nTurn over. No score.\n";
        m_scoreThisTurn = 0;
        std::cout << "Score banked this turn: " << m_scoreThisTurn << std::endl << std::endl;
        m_turnOver = true;
    }
    else {
        m_scoreThisTurn += roll;
    }
}
