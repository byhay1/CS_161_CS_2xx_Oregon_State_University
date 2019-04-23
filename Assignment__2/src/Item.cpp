#include "Item.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

//item characteristics
Item::Item(const std::string &itemName, const std::string &itemUnit, const int itemNumber, const double &itemPriceForUnit)
{
    this->itemName = itemName;
    //hashItemName();

    this->itemUnit = itemUnit;
    this->itemNumber = itemNumber;
    this->itemPriceForUnit = itemPriceForUnit;
}

Item::Item()
{
    this->itemName = "Not yet assigned";
    //hashItemName();

    this->itemUnit = "Not yet assigned";
    this->itemNumber = 0;
    this->itemPriceForUnit = 0.0;
}


#define A 54059 /* prime 1 */
#define B 76963 /* prime 2 */
#define C 86969 /* prime 3 */

//hash the item name
//void Item::hashItemName()
//{
//    std::string::iterator end_pos = std::remove(this->itemName.begin(), this->itemName.end(), ' ');
//    this->itemName.erase(end_pos, this->itemName.end());
//
//
//    unsigned h = 31 /* also prime */;
//    for(int i = 0; i < this->itemName.length(); ++i)
//    {
//        h = (h * A) ^ (this->itemName[0] * B);
//    }
//
//    hashCode = h;
//}

//return item name
std::string Item::getItemName() const
{
    return this->itemName;
}

//return item unit
std::string Item::getItemUnit() const
{
    return this->itemUnit;
}

//return item unit price
double Item::getItemUnitPrice() const
{
    return this->itemPriceForUnit;
}

//return item total price
double Item::getItemTotalPrice() const
{
    return this->itemPriceForUnit * this->itemNumber;
}

////return hash code
//int Item::getHashCode() const
//{
//    return this->hashCode;
//}

//print the item
void Item::printItem() const
{
    std::cout<<"name : " << itemName << " | " << "unit : " << itemUnit << " | " << "number : " << itemNumber << " | " << "unit_price : " << itemPriceForUnit << " | " << "extended_price : " << getItemTotalPrice() << std::endl;
}

Item& Item::operator=(const Item& rhs)
{
    if (this != &rhs)
    {
        this->itemName.assign(rhs.itemName);
        this->itemUnit.assign(rhs.itemUnit);

        this->itemNumber = rhs.itemNumber;
        this->itemPriceForUnit = rhs.itemPriceForUnit;
    }
    return *this;
}

bool Item::operator==(const Item& item)
{
    bool retVal = false;

    //if the name is the same
    if (this->itemName.compare(item.itemName) != 0)
        return retVal;

    //if the units are the same
    if (this->itemUnit.compare(item.itemUnit) != 0)
        return retVal;
    //if the itemNumber is the same
    if (this->itemNumber == item.itemNumber)
        return retVal;
    //if the unit price is the same
    if (this->itemPriceForUnit == item.itemPriceForUnit)
        return retVal;

    return true;
}

Item::~Item()
{}


