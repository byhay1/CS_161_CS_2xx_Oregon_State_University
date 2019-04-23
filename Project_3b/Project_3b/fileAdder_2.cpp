/*********************************************************************
** Author: Byron Hayes
** Date: 10/11/2015
** Description: Assignment 3: Project 3.b fileAdder.cpp
*********************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream userInFile; 
	ofstream userOutFile; 
	string file1;
	int counter = 0;
	int	integer; 
	int sum = 0; 

	cout << "Please enter the file name you would like to open (append .txt)" << '\n';
	getline(cin, file1);

	userInFile.open(file1);

		for (counter; counter < 7; counter++)
		{
			userInFile >> integer; 
			sum += integer;
		}
	userInFile.close(); 

	// Write to new file called sum.txt
	userOutFile.open("sum.txt");

		userOutFile << sum << endl; 

	userOutFile.close(); 

}