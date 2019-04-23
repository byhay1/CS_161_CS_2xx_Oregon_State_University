#include <iostream>
#include <string>

using namespace std;

string newStr;
string userStr;
int NUM = 5;
int *arr = new int[NUM];
double total = 0;
int select;

string reverseString(string rs, int track)
{
    if (track < 0)
    {
        return newStr;
    }
    else
    {
    newStr = newStr + rs[track];
    return reverseString(rs, track-1);
    }
}
int calcSum(int *a, int NUM, int ele)
{
    if (ele == -1)
    {
        return total;
    }
    else
    {
        total += arr[ele];
        return calcSum(a, NUM, (ele-1));
    }
}
//attempt on menu

//int menu(int s)
//{
//select = s;
//  switch(select)
//{
//case 1:
//    std::cout << "Please enter a string: " << std::endl;
//    std::cin >> userStr;
//    std::cout << reverseString(userStr, (userStr.length()-1)) << endl;
//    std::cout << std::endl << std::endl << std::endl;
//    break;
//case 2:
//    std::cout << "Please enter the amount of numbers you want to add" << std::endl;
//    std::cin >> NUM;
//    for (int i = 0; i < NUM; i++)
//    {
//        std::cout << "Please enter your " << i+1 << " number: " << std::endl;
//        std::cin >> arr[i];
//    }
//
//    std::cout<< "Total is: " << calcSum(arr, NUM, NUM-1) << std::endl;
//    delete [] arr;
//    break;
//default:
//    std::cout << "Try again" << std::endl;
//    std::cout << menu(select) << std:endl;
//}
//}
int main()
{
std::cout <<"If you want to write a word backwards press 1. \n"
          << "If you want to calculate the sum of numbers press 2." << std::endl;
std::cin >> select;

  switch(select)
{
case 1:
    std::cout << "Please enter a string: " << std::endl;
    std::cin >> userStr;
    std::cout << reverseString(userStr, (userStr.length()-1)) << endl;
    std::cout << std::endl << std::endl << std::endl;
    break;
case 2:
    std::cout << "Please enter the amount of numbers you want to add" << std::endl;
    std::cin >> NUM;
    for (int i = 0; i < NUM; i++)
    {
        std::cout << "Please enter your " << i+1 << " number: " << std::endl;
        std::cin >> arr[i];
    }

    std::cout<< "Total is: " << calcSum(arr, NUM, NUM-1) << std::endl;
    delete [] arr;
    break;
default:
    std::cout << "Try again" << std::endl;
    std::cin >> select;
}
// original testing of functions

//std::cout << "Please enter a string: " << std::endl;
//std::cin >> userStr;
//std::cout << reverseString(userStr, (userStr.length()-1)) << endl;
//
//std::cout << std::endl << std::endl << std::endl;
//
//std::cout << "Please enter the amount of numbers you want to add" << std::endl;
//std::cin >> NUM;
//for (int i = 0; i < NUM; i++)
//{
//    std::cout << "Please enter your " << i+1 << " number: " << std::endl;
//    std::cin >> arr[i];
//}
//
//std::cout<< "Total is: " << calcSum(arr, NUM, NUM-1) << std::endl;
//delete [] arr;
}
