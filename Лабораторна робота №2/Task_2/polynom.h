#ifndef POLYNOM_H
#define POLYNOM_H

#include <string>
#include <vector>

using namespace std;

class Polynom {

public:
    Polynom();
    Polynom(const string& expression);

    string add(const Polynom& other) const;
    string subtract(const Polynom& other) const;
    string multiply(const Polynom& other) const;

private:
    string correctData;
    vector<string> xGroup;
    vector<string> yGroup;
    vector<string> xPowerGroup;
    vector<string> yPowerGroup;
    vector<string> xyGroup;
    vector<string> xyPowerGroup;
    vector<string> constantGroup;


    string checkData(const string& getData);
    void divisionIntoGroups(const string& polynom);
    void changeSignInGroups();
    void changeSign(string& term);
    string processSimpleGroup(const vector<string>& group, char var, char action) const;
    string processGroupWithPower(const vector<string>& group, char var1, char var2, char action, bool isPower) const;
    string multiplyTerms(const string& term1, const string& term2, char var, bool isPower) const;
    int extractCoefficient(const string& term) const;
};

string solutionPolynomials(const Polynom &value1, char action, const Polynom &value2);

#endif // POLYNOM_H
