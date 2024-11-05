#include "manager.h"

Manager::Manager(string name, int id, int salary, Address addr, Department& dept, int bonus)
    : Employee(name, id, salary, addr, dept), bonus(bonus) {}

void Manager::setBonus(int newBonus)
{
    bonus = newBonus;
}

int Manager::getBonus()
{
    return bonus;
}
