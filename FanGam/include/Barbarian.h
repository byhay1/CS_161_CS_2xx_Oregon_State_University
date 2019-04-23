#ifndef BARBARIAN_H
#define BARBARIAN_H

#include <stdio.h>
#include "Creature.h"

class Barbarian : public Creature
{
public:
    Characters attack();
    bool defense(int);

    Characters whoAmI();
    void printName();

    Barbarian();
};


#endif // BARBARIAN_H
