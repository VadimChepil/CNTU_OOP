#ifndef INVENTORY_CPP
#define INVENTORY_CPP

#include "inventory.h"

template <typename T>
void Inventory<T>::addItem(const T& item) {
    items.push_back(item);
}

template <typename T>
void Inventory<T>::removeItemByName(const string& name) {
    auto it = remove_if(items.begin(), items.end(),
                             [&name](const T& item) { return item.getName() == name; });
    if (it != items.end()) {
        items.erase(it, items.end());
        cout << "Item \"" << name << "\" removed successfully.\n";
    } else {
        cout << "Item \"" << name << "\" not found.\n";
    }
}

template <typename T>
void Inventory<T>::displayAllItems() const {
    if (items.empty()) {
        cout << "Inventory is empty.\n";
        return;
    }
    cout << left << setw(15) << "Name"
              << setw(10) << "Price"
              << setw(10) << "Quantity" << endl;
    cout << "------------------------------------\n";
    for (const auto& item : items) {
        item.display();
    }
}

template <typename T>
void Inventory<T>::findItemsByPrice(double price) const {
    bool found = false;
    for (const auto& item : items) {
        if (item.getPrice() == price) {
            if (!found) {
                cout << "Items with price " << price << ":\n";
                cout << left << setw(15) << "Name"
                          << setw(10) << "Price"
                          << setw(10) << "Quantity" << std::endl;
                cout << "------------------------------------\n";
            }
            item.display();
            found = true;
        }
    }
    if (!found) {
        cout << "No items found with price " << price << ".\n";
    }
}

#endif // INVENTORY_CPP
