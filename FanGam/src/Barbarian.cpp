#include "Barbarian.h"

Barbarian::Barbarian() : Creature(2, 6, 2, 6, 0, 12) {}

Creature::Characters Barbarian::whoAmI()
{
    return Characters::Barbarian;
}

void Barbarian::printName()
{
    std::cout << "Barbarian";
}

Creature::Characters Barbarian::attack()
{

    attackNumber = 0;
    int i = 0;

    while (i < attackDieNumber) {
        attackNumber += randomDie(1, attackDieSides + 1);
        ++i;
    }

    return chooseDefender();
}

bool Barbarian::defense(int damage)
{

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
