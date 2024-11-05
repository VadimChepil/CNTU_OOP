#ifndef TOOL_H
#define TOOL_H

#include <string>

using namespace std;

class Tool
{
public:
    Tool(string name, int year);

    void setToolName(string name);
    string getToolName();

    void setYearManufacture(int year);
    int getYearManufacture();

private:
    string toolName;
    int yearManufacture;
};

#endif // TOOL_H
