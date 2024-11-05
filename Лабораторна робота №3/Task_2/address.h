#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

using namespace std;

class Address
{
public:
    Address(string street, string city);

    string getStreet();

    string getCity();

    void setStreet(string newStreet);

    void setCity(string newCity);

private:
    string street;
    string city;
};

#endif // ADDRESS_H
