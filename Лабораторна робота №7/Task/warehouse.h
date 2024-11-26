#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>
#include "sparePart.h"

using namespace std;

class Warehouse {
private:
    vector<SparePart> parts;

    vector<SparePart>::iterator findPartByName(const string& name);

public:
    void addPart(const SparePart& part);
    void displayParts() const;
    void removePart(const string& name);
    void updatePart(const string& name, double newPrice, int newQuantity);
};

#endif // WAREHOUSE_H
