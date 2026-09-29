#include "DIE.h"
#include <random>
Die::Die() {
    m_numOfSides = 6;
    m_dieValue = 1;
}

void Die::set_dieValue(int value) {
    m_dieValue = value;
}

int Die::get_dieValue() {
    return m_dieValue;
}

void Die::set_numOfSides(int sides) {
    if (sides == 2 || sides == 4 || sides == 6 || sides == 8 || sides == 12) {
        m_numOfSides = sides;
    }
    else {
        m_numOfSides = 6;
    }
}

int Die::get_numOfSides() {
    return m_numOfSides;
}

void Die::roll() {
    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, m_numOfSides);
    m_dieValue = distribution(generator);
}