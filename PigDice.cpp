#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>

class Die {
private:
    int m_numOfSides;
    int m_dieValue;

public:
Die() {
    m_numOfSides = 6;
    m_dieValue = 1;
    }

void set_dieValue(int value) {
    m_dieValue = value;
}

int get_dieValue() {
    return m_dieValue;
}

void set_numOfSides(int sides) {
    if (sides == 2 || sides == 4 || sides == 6 || sides == 8 || sides == 12) {
        m_numOfSides = sides;
    }
    else {
        m_numOfSides = 6;
    }
}

int get_numOfSides() {
    return m_numOfSides;
}

void roll() {
    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, m_numOfSides);
    m_dieValue = distribution(generator);
    }
};

struct GameState {
    char choice;
    int turn_count = 1;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};

void display_rules(GameState &mg);
void take_turn(GameState &mg);
void play_game(GameState &mg);
void roll_turn(GameState &mg);
void hold_turn(GameState &mg);

int main() {
    GameState my_game;
    display_rules(my_game);
    play_game(my_game);
    return 0;
}

void play_game(GameState &mg) {
    while (mg.game_over == false) {
        take_turn(mg);
        mg.game_score += mg.score_this_turn;
        if (mg.game_score >= 20) {
            mg.game_over = true;
        }
        else {
            mg.turn_over = false;
            mg.score_this_turn = 0;
            mg.turn_count = mg.turn_count + 1;
        }
    }
    std::cout << "You finished with a final score of "
    << mg.game_score << " in " << mg.turn_count << " turns!";
    std::cout << "\nThanks for playing Pig Dice!" << std::endl;
}

void display_rules(GameState &mg) {
    std::cout << "Let's Play PIG Dice!" << std::endl;
    std::cout << std::endl;
    std::cout << "* See how many turns it takes you to get to 20 points." << std::endl;
    std::cout << "* Turn ends when you hold or roll a 1." << std::endl;
    std::cout << "* If you roll a 1, you lose all points for the turn." << std::endl;
    std::cout << "* If you hold, you bank all points for the turn to the game score." << std::endl;
    std::cout << std::endl;
}

void take_turn(GameState &mg) {
    std::cout << "TURN " << mg.turn_count;
    std::cout << " - Game Score: " << mg.game_score;
    while (mg.turn_over == false) {
        std::cout << "\nroll or hold? (r/h): ";
        std::cin >> mg.choice;
        if (mg.choice == 'r') {
            roll_turn(mg);
        }
        else if (mg.choice == 'h') {
            hold_turn(mg);
        }
        else {
            std::cout << "Please enter a valid choice." << std::endl;
        }
    }
}

Die my_die;
void roll_turn(GameState &mg) {
    my_die.roll();
    int roll = my_die.get_dieValue();
    std::cout << "You rolled a " << roll << std::endl;
    if (roll == 1) {
        std::cout << "\nTurn over. No score.\n";
        mg.score_this_turn = 0;
        mg.turn_over = true;
    }
    else {
        mg.score_this_turn += roll;
    }
}

void hold_turn(GameState &mg) {
    mg.turn_over = true;
}