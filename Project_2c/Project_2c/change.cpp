/*********************************************************************
** Author: Byron Hayes
** Date: 10/05/2015
** Description: Assignment 2: Project 2.c (change.cpp)
*********************************************************************/

#include <iostream>
#include <string>

using namespace std; 

int main() {

	int pU, // pU is for Penny input by User
		Q, // Q is for Quarter (Quarter is 25 Pennies)
		D, // D is for Dime (Dime is 10 Pennies) 
		N, // N is for Nickel (Nickel is 5 Pennies) 
		P; // P is for Penny(or Cent) (Penny is 1 Penny)

	cout << "Please enter an amount in cents less than a dollar" << endl; // Prompt for User
	cin >> pU; 

	Q = pU / 25; // Calc Amount of Quarters
	D = (pU % 25) / 10; // Use Remainder to Calc Amount of Dimes
	N = ((pU % 25) - (D * 10)) / 5; // Use Previous Remainer to Calc Amount of Nickels
	P = ((pU % 25) - (D * 10) - (N * 5) / 1); // Use Previous Remainer to Calc Amount of Pennies

	cout << "Your change will be:" << endl; // Solution
	cout << "Q: " << Q << endl; 
	cout << "D: " << D << endl; 
	cout << "N: " << N << endl; 
	cout << "P: " << P << endl; 

	return 0; 

}