/*********************************************************************
** Author: Byron Hayes
** Date: 10/11/2015
** Description: Assignment 3: Project 3.b fileAdder.cpp
*********************************************************************/
/*
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string listOfInt;
	string uiFileName;
	int sum = 0; 
	int list;

	cout << "Please enter the file name you would like to open (append .txt)" << '\n';
	getline(cin,uiFileName);

	ifstream file1(uiFileName.c_str());
	if (file1.is_open())
	{
		ofstream file2("sum.txt");
		while (getline(file1, listOfInt))
		{
			int num = stoi(listOfInt);
			int nnum = 0;

			for (int counter; counter < 7; counter++) //while (int num = int nnum)
			{
				sum += stoi(listOfInt);
			}

			file2 << sum << endl;
			cout << sum << endl;
			file2.close();
		}
		file1.close();
	 }
	else
	{
		cout << "Could not access file" << endl;
	}
	return 0;

} 
*/