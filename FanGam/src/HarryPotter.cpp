#include "HarryPotter.h"

HarryPotter::HarryPotter() : Creature(2, 6, 2, 6, 0, 10), firstTime(true) {}

Creature::Characters HarryPotter::whoAmI()
{
    return Characters::HarryPotter;
}

void HarryPotter::printName()
{
    std::cout << "Harry Potter";
}

Creature::Characters HarryPotter::attack()
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

bool HarryPotter::defense(int damage)
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

    bool notLost = strengthPoint > 0;

    if (!notLost && firstTime)
    {
        strengthPoint = 20;
        firstTime = false;
        return true;
    }

    return notLost;
}
