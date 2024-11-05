#include "musician.h"

Musician::Musician(string name, Tool tool) : musicianName(name), tool(tool) {}

void Musician::setMusicianName(string name)
{
    musicianName = name;
}

string Musician::getMusicianName()
{
    return musicianName;
}

Tool Musician::getTool()
{
    return tool;
}
