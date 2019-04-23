//#pragma once
#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <math.h>

class Grid
{
protected:
	int** arr = new int*[ROWS]; //current array
	int** newArr = new int*[ROWS]; //new board with changes
public:
    int ROWS = 40;
    int COLS = 20;
	Grid();
};
#endif
