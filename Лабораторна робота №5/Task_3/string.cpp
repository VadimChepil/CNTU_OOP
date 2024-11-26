#include "String.h"
#include <iostream>

unsigned int String::my_strlen(const char* s) const {
    if (!s) return 0;
    unsigned int len = 0;
    while (s[len] != '\0') {
        ++len;
    }
    return len;
}

void String::my_strcpy(char* dest, const char* src) const {
    if (!dest || !src) return;
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
}

void String::my_strcat(char* dest, const char* src) const {
    if (!dest || !src) return;
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
}

int String::my_strcmp(const char* s1, const char* s2) const {
    if (!s1 || !s2) return -1;
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}

String::String() : str(nullptr), length(0) {}

String::String(const char* s) {
    if (s) {
        length = my_strlen(s);
        str = new char[length + 1];
        my_strcpy(str, s);
    } else {
        str = nullptr;
        length = 0;
    }
}

String::String(const String& other) {
    if (other.str) {
        length = other.length;
        str = new char[length + 1];
        my_strcpy(str, other.str);
    } else {
        str = nullptr;
        length = 0;
    }
}

String::~String() {
    delete[] str;
}

String& String::operator=(const String& other) {
    if (this == &other) return *this;
    delete[] str;
    length = other.length;
    str = new char[length + 1];
    my_strcpy(str, other.str);
    return *this;
}

String String::operator+(const String& other) const {
    String result;
    result.length = length + other.length;
    result.str = new char[result.length + 1];
    my_strcpy(result.str, str);
    my_strcat(result.str, other.str);
    return result;
}

bool String::operator==(const String& other) const {
    return my_strcmp(str, other.str) == 0;
}

bool String::operator!=(const String& other) const {
    return !(*this == other);
}

char& String::operator[](unsigned int index) {
    return str[index];
}

ostream& operator<<(ostream& os, const String& s) {
    if (s.str) {
        os << s.str;
    } else {
        os << "Empty string";
    }
    return os;
}

void String::concat(const String& other) {
    if (other.str == nullptr) return;

    unsigned int newLength = length + other.length;
    char* newStr = new char[newLength + 1];

    if (str != nullptr) {
        my_strcpy(newStr, str);
    }
    my_strcat(newStr, other.str);

    delete[] str;
    str = newStr;
    length = newLength;
}

void String::remove(unsigned int pos) {
    if (pos >= length || str == nullptr) return;
    for (unsigned int i = pos; i < length - 1; ++i) {
        str[i] = str[i + 1];
    }
    str[length - 1] = '\0';
    --length;
}

int String::compare(const String& other) const {
    return my_strcmp(str, other.str);
}

void String::print() const {
    if (str) {
        cout << str;
    } else {
        cout << "Empty string";
    }
}

unsigned int String::getLength() const {
    return length;
}

void String::sortStrings(String arr[], unsigned int size) {
    for (unsigned int i = 0; i < size - 1; ++i) {
        unsigned int minIndex = i;
        for (unsigned int j = i + 1; j < size; ++j) {
            if (arr[j].compare(arr[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            String temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
