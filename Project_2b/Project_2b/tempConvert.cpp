/*********************************************************************
** Author: Byron Hayes
** Date: 10/03/2015
** Description: Assignment 2: Project 2.b
*********************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {

	double C; // C is Celius
	double F; // F is Fahrenheit
	double frac = static_cast<double> (9) / 5;  // Name for fraction [ex. 9/5 ] in conversion formula 
	
	cout << "Please enter a Celcius temperature is: \n"; // Prompt for user to put in Celcius Temp
	cin >> C; 

    F = (frac) * C + 32; // Complete conversion formula 

	cout << "The equivalent Fahrenheit temperature is: \n"; // Print before answer and create a new line
	cout << F << endl; // Answer to formula
	
	return 0;

}