#include "Product.h"
#include "Inventory.h"

using namespace std;

int main()
{
    Inventory<Product> inventory;

    inventory.addItem(Product("Apple", 0.5, 100));
    inventory.addItem(Product("Laptop", 1000.0, 5));
    inventory.addItem(Product("T-shirt", 20.0, 50));
    inventory.addItem(Product("Banana", 0.5, 150));

    cout << "All items in inventory:\n";
    inventory.displayAllItems();
    cout << "\n";


    double searchPrice = 0.5;
    cout << "Searching for items with price " << searchPrice << ":\n";
    inventory.findItemsByPrice(searchPrice);
    cout << "\n";

    string nameToRemove = "Apple";
    cout << "Removing item \"" << nameToRemove << "\":\n";
    inventory.removeItemByName(nameToRemove);
    cout << "\n";

    std::cout << "Updated inventory:\n";
    inventory.displayAllItems();

    return 0;
}
