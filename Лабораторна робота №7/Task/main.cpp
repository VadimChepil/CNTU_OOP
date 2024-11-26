#include <iostream>
#include "warehouse.h"
#include "sparePart.h"

using namespace std;

int main() {
    Warehouse warehouse;

    warehouse.addPart({"Oil Filter", "Bosch", 250.0, 15});
    warehouse.addPart({"Brake Pads", "ATE", 1200.0, 8});
    warehouse.addPart({"Spark Plugs", "NGK", 500.0, 25});

    cout << "List of spare parts in the warehouse:\n";
    warehouse.displayParts();

    cout << "\nRemoving the part \"Brake Pads\":\n";
    warehouse.removePart("Brake Pads");

    cout << "\nUpdating the part \"Spark Plugs\":\n";
    warehouse.updatePart("Spark Plugs", 550.0, 30);

    cout << "\nUpdated list of spare parts in the warehouse:\n";
    warehouse.displayParts();

    return 0;
}
