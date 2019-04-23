//#pragma once
#ifndef SHAPES_H
#define SHAPES_H
#include <iostream>
#include <cmath>
#include "Grid.h"

class Shapes: public Grid
{
private:

public:

	double oscillator();
	double glider();
	double gliderCannon();
};


#endif
