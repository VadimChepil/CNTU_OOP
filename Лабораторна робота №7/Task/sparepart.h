#ifndef SPAREPART_H
#define SPAREPART_H

#include <string>

using namespace std;

struct SparePart
{
    string name;
    string manufacturer;
    double price;
    int quantity;

    void display() const;
};

#endif // SPAREPART_H
