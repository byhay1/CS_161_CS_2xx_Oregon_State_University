#include "BlueMen.h"

BlueMen::BlueMen() : Creature(2, 10, 3, 6, 3, 12) {}

Creature::Characters BlueMen::whoAmI()
{
    return Characters::BlueMen;
}

void BlueMen::printName()
{
    std::cout << "BlueMen";
}

Creature::Characters BlueMen::attack()
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

bool BlueMen::defense(int damage)
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

    defenceDieNumber -= damage % 4;

    return strengthPoint > 0;
}
