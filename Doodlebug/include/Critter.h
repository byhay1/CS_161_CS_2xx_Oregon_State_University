#ifndef CRITTER_H
#define CRITTER_H


class Critter
{
    public:
        Critter();
        void move();
        int breed();
        virtual ~Critter();
    protected:
    private:
        bool critter;
};

#endif // CRITTER_H
