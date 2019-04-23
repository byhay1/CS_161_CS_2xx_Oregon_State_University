//#pragma once
#ifndef GAME_H
#define GAME_H
#include "Shapes.h"
#include <iostream>
#include <cmath>

class Game
{
private:
	int** arr = new int*[ROWS]; //current array
	int** newArr = new int*[ROWS]; //new board with changes

public:
    Game(int);
    const int ROWS = 40;
    const int COLS = 20;
	int play();
	void printBoard();

};
#endif
