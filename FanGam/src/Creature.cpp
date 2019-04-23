#include "Creature.h"

Creature::Creature(int attackDieNumber,
                   int attackDieSides,
                   int defenceDieNumber,
                   int defenceDieSides,
                   int armor,
                   int strengthPoint) : attackDieNumber(attackDieNumber), attackDieSides(attackDieSides), defenceDieNumber(defenceDieNumber),
defenceDieSides(defenceDieSides), armor(armor), strengthPoint(strengthPoint), lost(false) {}

int Creature::randomDie(int start, int end)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(start, end);

    return dist(mt);
}

Creature::Characters Creature::chooseDefender()
{
    // choose random number and map them to creature types
    int discriminant = randomDie(0, 5);

    switch (discriminant)
    {
        case 0:
            return Medusa;
        case 1:
            return Barbarian;
        case 2:
            return Vampire;
        case 3:
            return BlueMen;
        case 4:
            return HarryPotter;
        default:
            return Medusa;
    }
}

void Creature::recover()
{
    strengthPoint += 4;
}

int Creature::getAttackNumber()
{
    return attackNumber;
}
