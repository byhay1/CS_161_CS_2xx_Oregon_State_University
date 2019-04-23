#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <stdio.h>
#include "Creature.h"

class Vampire : public Creature
{
public:
    Characters attack();
    bool defense(int);

    Characters whoAmI();
    void printName();

    Vampire();
};

#endif // VAMPIRE_H
