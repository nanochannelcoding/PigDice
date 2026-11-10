#ifndef PDGAMEV2_H
#define PDGAMEV2_H
#include "PDGame.h"
#include "DIE.h"
#include <iostream>
#include <string>

class PDGameV2 : public PDGame {
private:
    std::string m_playerName;
    int m_playerScore;
    int m_turnCount;
    Die m_myDie;

public:
    PDGameV2(const std::string& playerName): PDGame(),
    m_playerName(playerName),
    m_playerScore(0),
    m_turnCount(0) {
    }

    std::string getPlayerName() const {
        return m_playerName;
    }

    int getPlayerScore() const {
        return m_playerScore;
    }

    void setPlayerName(const std::string& name) {
        m_playerName = name;
    }

    void addPlayerScore(int points) {
        m_playerScore += points;
    }

    void playGame() {
        int runningScore = 0;
        char choice;
        bool turnOver = false;
        m_turnCount++;
        std::cout << "\n" << m_playerName << " (Score:" << m_playerScore << ") - TURN " << m_turnCount << std::endl;
        while (!turnOver) {
            std::cout << "roll or hold? (r/h): ";
            std::cin >> choice;
            if (choice == 'r' || choice == 'R') {
                m_myDie.roll();
                int dieValue = m_myDie.get_dieValue();
                if (dieValue == 1) {
                    std::cout << "Die: 1" << std::endl;
                    std::cout << "Turn over. No score." << std::endl;
                    runningScore = 0;
                    turnOver = true;
                }
                else {
                    runningScore += dieValue;
                    std::cout << "Die: " << dieValue
                    << " - Running score this turn: "
                    << runningScore << std::endl;
                }
            }
            else if (choice == 'h' || choice == 'H') {
                turnOver = true;
            }
            else {
                std::cout << "Please enter r or h." << std::endl;
            }
        }
        m_playerScore += runningScore;
        std::cout << "Score Banked This Turn: "
        << runningScore << std::endl;
    }
};

#endif // PDGAMEV2_H