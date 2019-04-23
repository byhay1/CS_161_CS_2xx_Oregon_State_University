/*********************************************************************
** Author: Byron Hayes
** Date: 10/10/2015
** Description: Group Project: Project 3.a (minmax.cpp)
*********************************************************************/


#include <iostream>
#include <string>
#include <iomanip>

using namespace std; 

int main()
{
	int x, y; 
	int value; 
	int minvalue = 0; 
	int maxvalue = 0; 
	

	cout << "How many integers would you like to enter? \n"; 
	cin >> x; 
	if (x > 0)
	{
		cout << "Please enter " << x << " integers." << endl;
		for (y = 1; y <= x; y++)
		{
			cin >> value;

			if (y == 1)
			{
				minvalue = maxvalue = value;
			}
			else
			{
				if (value > maxvalue) // checks if value is more than the current set maxvalue
					maxvalue = value; // If the above is true a new maxvalue will be set.  
				else if (value < minvalue) // checks if value is less than the current set minvalue
					minvalue = value; // If the above is true a new minvalue will be set.
			}
		}
	}
	else 
	{
		cout << "Please enter a positive integer" << endl; // Ends program if the user uses a non positive integer. 
	}
	cout << "min: " << minvalue << endl;  
	cout << "max: " << maxvalue << endl; 

	return 0; 
}