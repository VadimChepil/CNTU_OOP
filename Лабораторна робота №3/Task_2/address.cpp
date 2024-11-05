#include "address.h"

Address::Address(string street, string city) : street(street), city(city) {}

string Address::getStreet()
{
    return street;
}

string Address::getCity()
{
    return city;
}

void Address::setStreet(string newStreet)
{
    street = newStreet;
}

void Address::setCity(string newCity)
{
    city = newCity;
}
