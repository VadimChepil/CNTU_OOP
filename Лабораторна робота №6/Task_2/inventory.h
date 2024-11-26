#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class Inventory
{
private:
    vector<T> items;

public:
    void addItem(const T& item);
    void removeItemByName(const string& name);
    void displayAllItems() const;
    void findItemsByPrice(double price) const;
};

#include "inventory.cpp"

#endif // INVENTORY_H
