/*********************************************************************
** Author: Byron Hayes
** Date: 11/23/2015
** Description: Assignment 9: Project 9: Shopping Cart Source/Define.

Purpose of program is to take any set, be able to add and remove elements
within the set and compare sets, via union, set, and complimentary.
IntSet.cpp Source file which has the definitions of each
prototype from IntSet.hpp
*********************************************************************/

#include "IntSet.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

// constructor creates the dynamic array as ptrArr
// and sets each element, with max in set (10), as 0
IntSet::IntSet()
{
	ptrArr = new int[SIZE_MULTIPLIER];
	for (int i = 0; i < SIZE_MULTIPLIER; i++)
	{
		ptrArr[i] = 0;
	}
	arrSize = SIZE_MULTIPLIER;
	numValues = 0;
}

// destructor deletes array by with the use of custom
// function deleteArray()
IntSet::~IntSet()
{
	deleteArray(ptrArr, arrSize);
}

// the delete array function , passes the dynamic array by address
// and deletes it.
void IntSet::deleteArray(int* arr, int len)
{
	delete arr;
}
// simply returns the value of the size of the array
int IntSet::size() const
{
	return numValues;
}

// Simply returns true if IntSet has no integers
// false and true a '0' and '1'
int IntSet::isEmpty() const
{
	if (numValues == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// loops through the size of the array and
// checks to see if a value is in an array
// from left to right(positively)
int IntSet::contains(int cVal) const
{
	int i = 0;

	for (i = 0; i < numValues; i++)
    {
        if (ptrArr[i] == cVal)
            return 1;
    }
    return 0;
}

// custom function to find a value in the array
// and return its location in the array or -1
// meaning no location was found. (as arrays can
// can not have negative locations
int IntSet::getIndex(int cVal)
{
	int i = -1;

	for (i = 0; i < numValues; i++)
    {
        if (ptrArr[i] == cVal)
            return i;
    }
    return -1;
}


void IntSet::add(int aVal)
{
	// checks if aVal is not already in the IntSet
	if (contains(aVal) == 0)
    {
        // check to see if size is larger than current, make room
        if (numValues >= arrSize)
        {
            // Create a new dynamic array that is twice in size
            int *newArr;
            newArr = new int[arrSize+SIZE_MULTIPLIER];
            // loop and set each element to 0 to deal with garbage
            for (int i = 0; i < arrSize+SIZE_MULTIPLIER; i++)
            {
                newArr[i] = 0;
            }
            // Copy contents of the old array into new array
            for (int i = 0; i < arrSize; i++)
            {
                newArr[i] = ptrArr[i];
            }

            arrSize += SIZE_MULTIPLIER;
            // delete old array
            deleteArray(ptrArr, arrSize);
            // redirect data member pointer to new array
            ptrArr = newArr;
        }

        // finally add int to array and because of the add
        // increment numValues to account for the new add.
        ptrArr[numValues] = aVal;
        numValues++;

    }
}


void IntSet::remove(int valToRemove)
{
    // check to see if the value is in the array
    if (contains(valToRemove) == 1)
    {
        // get the location of the int to be removed
        int location = getIndex(valToRemove);

        // shifting over all of the subsequent elements of the array
        int i = 0;
        for (i = location; i < numValues; i++)
        {
            ptrArr[i] = ptrArr[i+1];
        }
        // make sure to blank out the previous 'last'
        ptrArr[numValues] = 0;
        // decrement number of values in array to account for the
        // element removed
        numValues--;
    }
}

void IntSet::addAll(const IntSet* setB)
{
    int i = 0;
    // loop through size of set
    for (i = 0; i < setB->size(); i++)
    {
        int val = (setB->ptrArr[i]);
        // check to see if this value is already in the current set
        // if not, then add it
        if (contains(val) == 0)
        {
            add(val);
        }
    }
}

void IntSet::removeDifferent(const IntSet* setB)
{
    int i = 0;
    // loop through current set 'backwards'
    for (i = numValues - 1; i >=0; i--)
    {
        int val = ptrArr[i];
        // if the current value is not in setB,
        // then remove it from this set
        if (setB->contains(val) == 0)
        {
            remove(val);
        }
    }
}

void IntSet::removeSame(const IntSet* setB)
{
    int i = 0;
    // loop through current set 'backwards'
    for (i = numValues - 1; i >=0; i--)
    {
        int val = ptrArr[i];
        // if the current value is in setB
        // then remove it from this set
        if (setB->contains(val) == 1)
        {
            remove(val);
        }
    }
}

//void IntSet::print()
//{
//    int i = 0;
//    for (i = 0; i < numValues - 1; i++)
//    {
//        cout << ptrArr[i] << ", ";
//    }
//    cout << ptrArr[i] << endl;
//}
//
//int main()
//{
//    IntSet setA;
//    IntSet setB;
//    int i = 0;
//    for (i = 1; i < 15; i++)
//    {
//        setA.add(i);
//    }
//    setA.print();
//
//    for (i = 5; i < 20; i++)
//    {
//        setB.add(i);
//    }
//    setB.print();

//    setA.addAll(&setB);
//    cout << "After Add all" << endl;
//    cout << "Set A: ";
//    setA.print();
//    cout << "Set B: ";
//    setB.print();

//    setA.removeDifferent(&setB);
//    cout << "After Remove Different" << endl;
//    cout << "Set A: ";
//    setA.print();
//    cout << "Set B: ";
//    setB.print();
//
//
//    setA.removeSame(&setB);
//    cout << "After Remove Same" << endl;
//    cout << "Set A: ";
//    setA.print();
//    cout << "Set B: ";
//    setB.print();

//    cin.get();
//    return 0;
//}

