#ifndef HARRYPOTTER_H
#define HARRYPOTTER_H

#include <stdio.h>
#include "Creature.h"

class HarryPotter : public Creature
{
private:
    bool firstTime;

public:
    Characters attack();
    bool defense(int damage);

    Characters whoAmI();
    void printName();

    HarryPotter();
};

#endif // HARRYPOTTER_H
