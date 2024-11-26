#include "String.h"
#include <iostream>

using namespace std;

int main()
{
    String greeting("Hello");
    String name("Taras");
    String exclamation("!");

    // Демонстрація оператора +
    String message = greeting + ", " + name + exclamation;
    cout << "Concatenated message: " << message << endl;

    // Демонстрація оператора порівняння ==
    String anotherGreeting("Hello");
    if (greeting == anotherGreeting)
    {
        cout << "Greetings are equal." << endl;
    }

    // Демонстрація оператора порівняння !=
    if (name != greeting)
    {
        cout << "Name and greeting are different." << endl;
    }

    // Демонстрація оператора індексації []
    cout << "First character of greeting: " << greeting[0] << endl;

    // Заміна символу
    name[0] = 'a';
    cout << "Modified name: " << name << endl;

    // Видалення символу з рядка
    String sentence("Hello, world!");
    sentence.remove(5); // Видалення коми
    cout << "Sentence without comma: " << sentence << endl;

    // Конкатенація
    sentence.concat(String(" How are you?"));
    cout << "Extended sentence: " << sentence << endl;

    // Масив рядків
    String words[] = { String("Banana"), String("Apple"), String("Cherry"), String("Date") };
    unsigned int size = 4;

    cout << "Unsorted words: ";
    for (unsigned int i = 0; i < size; i++)
    {
        cout << words[i] << " ";
    }
    cout << endl;

    // Сортування масиву рядків
    String::sortStrings(words, size);

    cout << "Sorted words: ";
    for (unsigned int i = 0; i < size; i++)
    {
        cout << words[i] << " ";
    }
    cout << endl;

    return 0;
}
