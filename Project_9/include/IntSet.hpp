/*********************************************************************
** Author: Byron Hayes
** Date: 11/23/2015
** Description: Assignment 9: Project 9: Shopping Cart Header

IntSet.hpp holds the prototype functions and constructors
to be used by the IntSet.cpp and main.cpp.
*********************************************************************/

#ifndef INTSET_HPP
#define INTSET_HPP
#include <iostream>
#include <cstdlib>

class IntSet
{
private:
    // static constant so that it can not be changed
    // and is accessible without the use of this.
    static const int SIZE_MULTIPLIER = 10;
	int arrSize; //how many slots there are
	int numValues; //how many are full
	int * ptrArr; // point to array


public:
    // constructor and destructor
	IntSet();
	~IntSet();

    // function prototypes with size(),
    // isEmpty(), and contains() set as constants
    // so they could be used by functions with const.
    // parameter
	int size() const;
	int isEmpty() const;
	int contains(int) const;
	void add(int);
	void remove(int);
	void addAll(const IntSet*);
	void removeDifferent(const IntSet*);
	void removeSame(const IntSet*);
	void deleteArray(int*, int);
	int getIndex(int);
	//void print(); testing purposes
};

#endif // INTSET_HPP
