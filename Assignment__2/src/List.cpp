#include "List.h"
#include <iostream>

//constructor initialization
List::List():
itemList(new Item[initialCapacity]),
Log(0),
totalPrice(0),
size(0){}

void List::erase(Item& item)
{
    //find the item in the list
    int location = itemIndex(item);

    //loop through and move the other items 'up' in the list
    if (location == (size - 1)) //we are on the last item in the list
    {
        //do nothing - ignore this item
    }
    else
    {
        //move everything after this item up one slot
        int i;
        for (i = location; i < (size -1); i++)
        {
            itemList[i] = itemList[i + 1];
        }
    }

    //decrement the size of the list
    size--;

}

void List::addItem(const Item& item)
{
    if (ifItemExists(item))
    {
        return;
    }

    if (size >= capacity)
    {
        reserve(1 << Log);
        Log++;
    }
    itemList[size] = item;
    ++size;
    totalPrice += item.getItemTotalPrice();
}


int List::itemIndex(const Item &item) const
{
    for(int i = 0; i < size; ++i)
    {
        if (itemList[i] == item)
        {
            return i;
        }
    }

    return -1;
}

bool List::ifItemExists(const Item &item) const
{
    for(int i = 0; i < size; ++i)
    {
        if (itemList[i] == item)
        {
            return true;
        }
    }

    return false;
}

void List::reserve(unsigned int capacity)
{
    Item * newBuffer = new Item[capacity];

    for (unsigned int i = 0; i < size; i++)
    {
        newBuffer[i] = itemList[i];
    }

    this->capacity = capacity;
    delete[] itemList;
    itemList = newBuffer;
}

const void List::displayAllCarts() const
{
    for(int i = 0; i < size; ++i)
    {
        itemList[i].printItem();
    }

    std::cout << "total price of all items : " << totalPrice << std::endl;
}

List::~List()
{
    delete[] itemList;
}
