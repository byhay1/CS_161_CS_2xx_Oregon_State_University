#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item {

private:
    //void hashItemName();

public:
    std::string itemName;  //item name
    std::string itemUnit; //item unit
    int itemNumber; //number to buy
    double itemPriceForUnit;    //unit price
    //int hashCode;    //hash code

public:
    Item(const std::string &itemName, const std::string &itemUnit, const int itemNumber, const double &itemPrice);
    Item();
    // prototype item functions
    void printItem() const;
    std::string getItemName() const;
    std::string getItemUnit() const;
    int getItemNumber() const;
    double getItemUnitPrice() const;
    double getItemTotalPrice() const;
    //int getHashCode() const;
    Item& operator= (const Item&);
    bool operator== (const Item&);

    ~Item();
};

#endif // ITEM_H
