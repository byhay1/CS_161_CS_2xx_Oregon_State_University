#include <iostream>
#include <stack>
#include <deque>
#include <vector>

#include "Medusa.h"
#include "Vampire.h"
#include "BlueMen.h"
#include "Barbarian.h"
#include "HarryPotter.h"

Creature* chooseCreature(int chooser)
{
    switch (chooser)
    {
        case 0:
            return new Medusa();

        case 1:
            return new Barbarian();

        case 2:
            return new BlueMen();

        case 3:
            return new HarryPotter();

        case 4:
            return new Vampire();

        default:
            return new Vampire();
    }
}

int random(int start, int end)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(start, end);

    return dist(mt);
}

struct CreatureTeam
{
    std::string team;
    Creature* creature;
}

creatureTeam;
std::stack<Creature*> looserPile;
std::vector<CreatureTeam> firstThreeFinishers;

std::deque<Creature*> firstPlayerLineUp;
std::deque<Creature*> secondPlayerLineUp;

int main(int argc, const char * argv[])
{
    int numberOfPlayers;

    std::cout << "Please input the number of players (the number will be used for both teams)\n";
    std::cin >> numberOfPlayers;


    int i = 0;

    //initialize first player team
    while (i < numberOfPlayers)
    {
        firstPlayerLineUp.push_back(chooseCreature(random(0, 5)));
        ++i;
    }

    //initialize second player team
    i = 0;
    while (i < numberOfPlayers)
    {
        secondPlayerLineUp.push_back(chooseCreature(random(0, 5)));
        ++i;
    }

    // tournament
    while (!firstPlayerLineUp.empty() && !secondPlayerLineUp.empty())
    {
        // taking fighter from first team
        Creature *firstPlayer = firstPlayerLineUp.back();

        // taking fighter from second team
        Creature *secondPlayer = secondPlayerLineUp.back();

        std::cout << "--------------- NOW FIGHTING -----------------\n";
        std::cout << "--------------- ";
        firstPlayer->printName(); std::cout <<  " VS " ; secondPlayer->printName();
        std::cout << "--------------- \n\n";

        bool firstWon = false;
        bool secondWon = false;

        while(true)
        {
            bool won;

            //first attacks, second one defenses
            firstPlayer->attack();
            won = secondPlayer->defense(firstPlayer->getAttackNumber());
            if (!won)
            {
                firstPlayer->printName(),
                std::cout << " wins!!\n\n";

                if (firstThreeFinishers.size() < 3)
                {
                    creatureTeam.creature = firstPlayer;
                    creatureTeam.team = "first";

                    firstThreeFinishers.push_back(creatureTeam);
                }
                firstWon = true;
                break;
            }

            //second attacks, first one defenses
            secondPlayer->attack();
            won = firstPlayer->defense(secondPlayer->getAttackNumber());
            if (!won)
            {
                secondPlayer->printName(),
                std::cout << " wins!!\n\n";
                if (firstThreeFinishers.size() < 3)
                {
                    creatureTeam.creature = secondPlayer;
                    creatureTeam.team = "second";

                    firstThreeFinishers.push_back(creatureTeam);
                }
                secondWon = true;
                break;
            }

        }

        if (firstWon)
        {
            firstPlayerLineUp.pop_back();

            //recovering
            firstPlayer->recover();

            firstPlayerLineUp.push_front(firstPlayer);

            secondPlayerLineUp.pop_back();
            looserPile.push(secondPlayer);
        }
        else
        {
            secondPlayerLineUp.pop_back();

            //recovering
            secondPlayer->recover();

            secondPlayerLineUp.push_front(secondPlayer);

            firstPlayerLineUp.pop_back();
            looserPile.push(firstPlayer);
        }

    }

    std::cout << "\n\n\n Displaying First Three Finishers \n\n";
    for (CreatureTeam creatureTeam : firstThreeFinishers)
    {
        std::cout << "Team : " << creatureTeam.team << "\n";
        std::cout << "Player : "; creatureTeam.creature->printName(); std::cout << "\n\n";

    }

    std::cout << "\n\n\n Displaying Looser Pile \n\n";

    while (!looserPile.empty())
    {
        looserPile.top()->printName();
        std::cout << "\n";
        looserPile.pop();
    }


    return 0;
}
