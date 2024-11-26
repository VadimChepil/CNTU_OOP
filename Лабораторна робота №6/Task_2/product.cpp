#include "product.h"
#include <iostream>
#include <iomanip>

Product::Product(const string& name, double price, int quantity)
    : name(name), price(price), quantity(quantity) {}


string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }

void Product::setQuantity(int newQuantity) { quantity = newQuantity; }

void Product::display() const {
    cout << left << setw(15) << name
              << setw(10) << price
              << setw(10) << quantity << endl;
}
