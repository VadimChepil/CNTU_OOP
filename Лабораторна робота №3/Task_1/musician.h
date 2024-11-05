#ifndef MUSICIAN_H
#define MUSICIAN_H

#include <string>
#include "tool.h"

using namespace std;

class Musician
{
public:
    Musician(string name, Tool tool);

    void setMusicianName(string name);
    string getMusicianName();

    Tool getTool();

private:
    string musicianName;
    Tool tool; // агрегація
};

#endif // MUSICIAN_H
