#include "warehouse.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<SparePart>::iterator Warehouse::findPartByName(const string& name)
{
    return find_if(parts.begin(), parts.end(), [&name](const SparePart& part)
    {
        return part.name == name;
    });
}

void Warehouse::addPart(const SparePart& part)
{
    parts.push_back(part);
}

void Warehouse::displayParts() const
{
    if (parts.empty())
    {
        cout << "The warehouse is empty.\n";
        return;
    }

    cout << string(65, '~') << "\n";
    cout << left << "|" << setw(20) << "Name"
                << "|" << setw(20) << "Manufacturer"
                << "|" << setw(10) << "Price"
                << "|" << setw(10) << "Quantity" << "|" << "\n";


    for (SparePart part : parts)
    {
        part.display();
    }
    cout << string(65, '~') << "\n";
}

void Warehouse::removePart(const string& name)
{
    vector<SparePart>::iterator it = findPartByName(name);
    if (it != parts.end())
    {
        parts.erase(it);
        cout << "The part \"" << name << "\" was removed from the warehouse.\n";
    }
    else
    {
        cout << "The part \"" << name << "\" was not found.\n";
    }
}

void Warehouse::updatePart(const string& name, double newPrice, int newQuantity)
{
    vector<SparePart>::iterator it = findPartByName(name);
    if (it != parts.end())
    {
        it->price = newPrice;
        it->quantity = newQuantity;
        cout << "The part \"" << name << "\" was updated.\n";
    }
    else
    {
        cout << "The part \"" << name << "\" was not found.\n";
    }
}
