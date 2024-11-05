#ifndef VOCALIST_H
#define VOCALIST_H

#include "musician.h"

class Vocalist : public Musician
{
public:
    Vocalist(string name, Tool tool, string vocalistType);

    string getVocalistType();

private:
    string vocalistType;
};

#endif // VOCALIST_H
