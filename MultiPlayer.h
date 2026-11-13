#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H
#include "PDGameV2.h"
#include <iostream>
#include <string>
#include <vector>

class MultiPlayer {
private:
    std::vector<PDGameV2> m_players;
    bool m_gameOver;
    void displayRules() {
        std::cout << "\nLet's Play PIG Dice!\n" << std::endl;
        std::cout << "* See which player will reach 50 points in the fewest turns." << std::endl;
        std::cout << "* Turn ends when you hold or roll a 1" << std::endl;
        std::cout << "* If you roll a 1, you lose all points for the turn." << std::endl;
        std::cout << "* If you hold, you save all points for the turn." << std::endl;
        std::cout << std::endl;
    }

void displayScoreBoard() {
        for (std::size_t i = 0; i < m_players.size(); i++) {
            std::cout << m_players[i].getPlayerName() << " (Score:" << m_players[i].getPlayerScore() << ") | ";
        }
        std::cout << std::endl << std::endl;
    }

void checkForWinner() {
        for (std::size_t i = 0; i < m_players.size(); i++) {
            if (m_players[i].getPlayerScore() >= 50) {
                m_gameOver = true;
                return;
            }
        }
    }

public:
    MultiPlayer(const std::string& unused = ""):
    m_gameOver(false) {
        int numberOfPlayers;
        while (1) {
            try {
                std::cout << "How many people are playing? ";
                std::cin >> numberOfPlayers;
                if (std::cin.fail()) {
                    throw 101;
                }
                if (numberOfPlayers < 2) {
                    std::cout << "Please enter at least 2 players: ";
                    std::cin >> numberOfPlayers;
                }
                break;
            }
            catch (int e) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Please enter an integer next time! Error " << e << std::endl;
            }
        }
        for (int i = 0; i < numberOfPlayers; i++) {
            std::string playerName;
            std::cout << "Enter player " << i + 1 << "'s name: ";
            std::getline(std::cin, playerName);
            if (playerName.empty()) {
                playerName = "Anonymous Player " + std::to_string(i + 1);
            }
            m_players.emplace_back(playerName);
        }
        displayRules();
        mpPlayGame();
    }
void mpPlayGame() {
        while (!m_gameOver) {
            for (std::size_t i = 0;
                i < m_players.size() && !m_gameOver; i++) {
                    m_players[i].playGame();
                    displayScoreBoard();
                    checkForWinner();
                }
        }
        for (std::size_t i = 0; i < m_players.size(); i++) {
            if (m_players[i].getPlayerScore() >= 50) {
                std::cout << "\nCongratulations! " << m_players[i].getPlayerName() << " you win with a score of " << m_players[i].getPlayerScore() << std::endl;
                break;
            }
        }
    }
};

#endif // MULTIPLAYER_H