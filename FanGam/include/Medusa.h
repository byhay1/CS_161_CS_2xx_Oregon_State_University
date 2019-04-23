#ifndef MEDUSA_H
#define MEDUSA_H

#include <stdio.h>
#include "Creature.h"

class Medusa : public Creature
{
public:
    Characters attack();
    bool defense(int);

    Characters whoAmI();
    void printName();

    Medusa();
};

#endif // MEDUSA_H
