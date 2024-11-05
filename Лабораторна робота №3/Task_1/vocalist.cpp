#include "vocalist.h"

Vocalist::Vocalist(string name, Tool tool, string vocalistType)
    : Musician(name, tool), vocalistType(vocalistType) {}

string Vocalist::getVocalistType()
{
    return vocalistType;
}
