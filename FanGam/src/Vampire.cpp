#include "Vampire.h"

Vampire::Vampire() : Creature(1, 12, 1, 6, 1, 18) {}

Creature::Characters Vampire::whoAmI()
{
    return Characters::Vampire;
}

void Vampire::printName()
{
    std::cout << "Vampire";
}

Creature::Characters Vampire::attack()
{
    attackNumber = 0;
    int i = 0;

    while (i < attackDieNumber)
    {
        attackNumber += randomDie(1, attackDieSides + 1);
        ++i;
    }

    return chooseDefender();
}

bool Vampire::defense(int damage)
{
    int charm = randomDie(0, 101);

    //if random number is under 50, then vampire has charmed the attacker so nothing happens.
    if (charm < 50)
    {
        return true;
    }


    int defenseNumber = 0;
    int i = 0;

    while (i < defenceDieNumber)
    {
        defenseNumber += randomDie(1, defenceDieSides + 1);
        ++i;
    }

    damage -= (armor + defenseNumber);

    if (damage > 0)
    {
        strengthPoint -= damage;
    }

    return strengthPoint > 0;
}
