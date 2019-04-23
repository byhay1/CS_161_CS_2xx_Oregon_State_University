#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <random>

class Creature
{
protected:
    //attack
    int attackDieNumber;
    int attackDieSides;

    //defense
    int defenceDieNumber;
    int defenceDieSides;

    //Armor
    int armor;

    //Strength
    int strengthPoint;

    //attack number
    int attackNumber;

    Creature(int, int, int, int, int, int);

    bool lost;

public:

    //Universe characters
    enum Characters
    {
        Medusa, Barbarian, Vampire, BlueMen, HarryPotter
    };

    virtual Characters attack() = 0;

    // argument is the number of attack
    // returns true if characters does not loose
    virtual bool defense(int) = 0;

    // [start, end)
    int randomDie(int start, int end);

    virtual Characters whoAmI() = 0;
    virtual void printName() = 0;

    int getAttackNumber();

    void recover();

protected:

    //randomly choose defense Character
    Characters chooseDefender();
};

#endif // CREATURE_H
