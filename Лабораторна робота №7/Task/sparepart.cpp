#include "sparePart.h"
#include <iostream>
#include <iomanip>

SparePart::SparePart() : name(""), manufacturer(""), price(0.0), quantity(0) {}

SparePart::SparePart(string name, string manufacturer, double price, int quantity)
    : name(name), manufacturer(manufacturer), price(price), quantity(quantity) {}

string SparePart::getName() const
{
    return name;
}

string SparePart::getManufacturer() const
{
    return manufacturer;
}

double SparePart::getPrice() const
{
    return price;
}

int SparePart::getQuantity() const
{
    return quantity;
}

void SparePart::setName(string name)
{
    this->name = name;
}

void SparePart::setManufacturer(string manufacturer)
{
    this->manufacturer = manufacturer;
}

void SparePart::setPrice(double price)
{
    if (price >= 0)
    {
        this->price = price;
    }
    else
    {
        cout << "The price cannot be negative" << endl;
    }
}

void SparePart::setQuantity(int quantity)
{
    if (quantity >= 0)
    {
        this->quantity = quantity;
    }
    else
    {
        cout << "The number cannot be negative!" << endl;
    }
}

void SparePart::display() const
{
    cout << left << "|" << setw(20) << name
         << "|" << setw(20) << manufacturer
         << "|" << setw(10) << price
         << "|" << setw(10) << quantity << "|" << endl;
}
