#ifndef LIST_H
#define LIST_H
#include "Item.h"

class List {
private:
    int static const initialCapacity = 4;
    int size;
    int capacity;
    int Log;
    double totalPrice;
    Item* itemList;
    bool ifItemExists(const Item& item) const;
public:
    List();

    const void displayAllCarts() const;
    void addItem(const Item& item);
    void reserve(unsigned int capacity);
    void erase(Item& item);
    int itemIndex(const Item &item) const;

    ~List();
};

#endif // LIST_H
