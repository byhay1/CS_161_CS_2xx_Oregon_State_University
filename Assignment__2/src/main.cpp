#include <iostream>
#include <cmath>
#include <climits>
#include "List.h"

int main(int argc, char * argv[])

{
    List testList;

    while(true)
    {
        std::string itemName;
        std::string itemUnit;
        int itemNumber;
        double itemUnitPrice;

        std::cout<<"enter item name : ";
        std::getline(std::cin, itemName);


        std::cout<<"enter item unit : ";
        std::getline(std::cin, itemUnit);

        std::cout<<"enter item number : ";
        std::cin>>itemNumber;

        std::cout<<"enter item price : ";
        std::cin>>itemUnitPrice;

        Item item(itemName, itemUnit, itemNumber, itemUnitPrice);
        testList.addItem(item);

        std::cout<<std::endl<<std::endl<<"---------------------" << std::endl;
        std::cout<<"type anything to continue and \"q\" for quit" << std::endl;

        char key;
        std::cin>>key;
        std::cin.clear();
        std::cin.ignore(INT_MAX,'\n');

        // ASCII code 81 for "Q" and 113 for "q"
        if (key == 'q' || key == 'Q')
        {
            break;
        }

    }


    std::cout<<std::endl<<std::endl<<"---------------------" << std::endl;

    //testing erase
    Item itemForRemoval("potato", "pound", 4, 2);
    testList.erase(itemForRemoval);

    //displaying all in cart
    testList.displayAllCarts();

    return 0;
}
