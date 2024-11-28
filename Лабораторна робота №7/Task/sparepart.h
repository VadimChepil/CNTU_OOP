#ifndef SPAREPART_H
#define SPAREPART_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class SparePart {
private:
    string name;
    string manufacturer;
    double price;
    int quantity;

public:
    SparePart();

    SparePart(string name, string manufacturer, double price, int quantity);

    string getName() const;
    string getManufacturer() const;
    double getPrice() const;
    int getQuantity() const;

    void setName(string name);
    void setManufacturer(string manufacturer);
    void setPrice(double price);
    void setQuantity(int quantity);

    void display() const;
};

#endif // SPAREPART_H
