#include <iostream>
#include <ctime>
#include <cstdlib>

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
    GameState my_game; // instantiate a GameState object
    display_rules(my_game); // call the display_rules function
    play_game(my_game); // call the play_game function and pass the GameState object
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
    std::cout << "\nScore Banked This Turn: " << mg.score_this_turn
    << std::endl << std::endl;
}
void roll_turn(GameState &mg) {
    srand(time(NULL));
    int die = rand() % 6 + 1;
    std::cout << "Die: " << die;
    if (die == 1) {
        std::cout << "\nTurn over. No score.";
        mg.score_this_turn = 0;
        mg.turn_over = true;
    }
    else {
        mg.score_this_turn = mg.score_this_turn + die;
        std::cout << " - Running score this turn: " << mg.score_this_turn;
    }
}
void hold_turn(GameState &mg) {
    mg.turn_over = true;
}

