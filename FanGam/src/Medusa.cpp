#include "Medusa.h"

Medusa::Medusa() : Creature(2, 6, 1, 6, 3, 8){}

Creature::Characters Medusa::whoAmI()
{
    return Characters::Medusa;
}

void Medusa::printName()
{
    std::cout << "Medusa";
}

Creature::Characters Medusa::attack()
{
    attackNumber = 0;
    int i = 0;

    while (i < attackDieNumber)
    {
        attackNumber += randomDie(1, attackDieSides + 1);
        ++i;
    }

    // Medusa Wins
    if(attackNumber == 12)
    {
        attackNumber = 4000;
    }

    return chooseDefender();
}

bool Medusa::defense(int damage)
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

