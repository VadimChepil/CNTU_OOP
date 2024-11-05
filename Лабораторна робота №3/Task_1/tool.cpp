#include "tool.h"

Tool::Tool(string name, int year) : toolName(name), yearManufacture(year) {}

void Tool::setToolName(string name)
{
    toolName = name;
}

string Tool::getToolName()
{
    return toolName;
}

void Tool::setYearManufacture(int year)
{
    yearManufacture = year;
}

int Tool::getYearManufacture()
{
    return yearManufacture;
}
