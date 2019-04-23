#ifndef BLUEMEN_H
#define BLUEMEN_H

#include <stdio.h>
#include "Creature.h"

class BlueMen : public Creature
{
public:
    Characters attack();
    bool defense(int damage);

    Characters whoAmI();
    void printName();

    BlueMen();
};

#endif // BLUEMEN_H
