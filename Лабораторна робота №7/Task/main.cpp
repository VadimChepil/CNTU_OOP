#include <iostream>
#include "warehouse.h"

using namespace std;

int main()
{
    Warehouse warehouse;

    warehouse.addPart({"Oil Filter", "Bosch", 250.0, 15});
    warehouse.addPart({"Brake Pads", "ATE", 1200.0, 8});
    warehouse.addPart({"Spark Plugs", "NGK", 500.0, 25});

    cout << "List of spare parts in the warehouse:" << endl;
    warehouse.displayParts();

    cout << endl << "Removing the part \"Brake Pads\":" << endl;
    warehouse.removePart("Brake Pads");

    cout << endl << "Updating the part \"Spark Plugs\":" << endl;
    warehouse.updatePart("Spark Plugs", 550.0, 30);

    cout << endl << "Updated list of spare parts in the warehouse:" << endl;
    warehouse.displayParts();

    return 0;
}
