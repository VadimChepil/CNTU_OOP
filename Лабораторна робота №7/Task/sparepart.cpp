#include "SparePart.h"
#include <iostream>
#include <iomanip>

void SparePart::display() const
{
    cout << left << "|" << setw(20) << name
            << "|" << setw(20) << manufacturer
            << "|" << setw(10) << price
            << "|" << setw(10) << quantity << "|" << "\n";
}
