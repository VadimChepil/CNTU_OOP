#include "warehouse.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<SparePart>::iterator Warehouse::findPartByName(const string& name)
{
    return find_if(parts.begin(), parts.end(), [&name](const SparePart& part)
    {
        return part.getName() == name;
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
        cout << "The warehouse is empty." << endl;
        return;
    }

    cout << string(65, '~') << endl;
    cout << left << "|" << setw(20) << "Name"
                << "|" << setw(20) << "Manufacturer"
                << "|" << setw(10) << "Price"
                << "|" << setw(10) << "Quantity" << "|" << endl;


    for (const SparePart& part : parts)
    {
        part.display();
    }
    cout << string(65, '~') << endl;
}

void Warehouse::removePart(const string& name)
{
    vector<SparePart>::iterator it = findPartByName(name);
    string message = "The part \"";
    if (it != parts.end())
    {
        parts.erase(it);
        message += name + "\" was removed from the warehouse.";
    }
    else
    {
        message += name + "\" was not found.";
    }
    cout << message << endl;
}

void Warehouse::updatePart(const string& name, double newPrice, int newQuantity)
{
    vector<SparePart>::iterator it = findPartByName(name);
    string message = "The part \"";
    if (it != parts.end())
    {
        it->setPrice(newPrice);
        it->setQuantity(newQuantity);
        message += name + "\" was updated.";
    }
    else
    {
        message += name + "\" was not found.";
    }
    cout << message << endl;
}
