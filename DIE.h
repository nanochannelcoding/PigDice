#ifndef PIGDICE_DIE_H
#define PIGDICE_DIE_H

class Die {
private:
    int m_numOfSides;
    int m_dieValue;
public:
    Die();
    void set_dieValue(int value);
    int get_dieValue();
    void set_numOfSides(int sides); //4, 6, 8, 10, 12 sides. Default 6.
    int get_numOfSides();
    void roll();
};


#endif //PIGDICE_DIE_H