#ifndef STRING_H
#define STRING_H

#include <iostream>

using namespace std;

class String
{
private:
    char* str;
    unsigned int length;

    unsigned int my_strlen(const char* s) const;
    void my_strcpy(char* dest, const char* src) const;
    void my_strcat(char* dest, const char* src) const;
    int my_strcmp(const char* s1, const char* s2) const;

public:
    String();
    String(const char* s);
    String(const String& other);
    ~String();

    // Оператори
    String& operator=(const String& other);            // оператор присвоєння
    String operator+(const String& other) const;       // оператор +
    bool operator==(const String& other) const;        // оператор порівняння ==
    bool operator!=(const String& other) const;        // оператор порівняння !=
    char& operator[](unsigned int index);              // оператор індексації
    friend ostream& operator<<(ostream& os, const String& s); // оператор виведення <<

    void concat(const String& other);
    void remove(unsigned int pos);
    int compare(const String& other) const;
    void print() const;
    unsigned int getLength() const;

    static void sortStrings(String arr[], unsigned int size);
};

#endif // STRING_H
