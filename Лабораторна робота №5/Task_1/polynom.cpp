#include "polynom.h"
#include <iostream>
#include <cctype>

using namespace std;

Polynom::Polynom() {}

Polynom::Polynom(const string& expression) {
    correctData = checkData(expression);
    if (correctData != "Invalid data!") {
        divisionIntoGroups(correctData);
    } else {
        cout << correctData << endl;
    }
}

string Polynom::getCorrectData()
{
    return correctData;
}

// Перевантаження оператора +
Polynom Polynom::operator+(const Polynom& other) const {
    Polynom result;
    result.correctData = this->add(other);
    return result;
}

// Перевантаження оператора -
Polynom Polynom::operator-(const Polynom& other) const {
    Polynom result;
    result.correctData = this->subtract(other);
    return result;
}

// Перевантаження оператора *
Polynom Polynom::operator*(const Polynom& other) const {
    Polynom result;
    result.correctData = this->multiply(other);
    return result;
}

string Polynom::checkData(const string& getData) {
    char allowSymbols[] = {'x', 'y', 'z', '-', '+', '*', '^'};
    bool checkSymbol = false;
    string correctData;

    for (char c : getData) {
        if (isdigit(c)) {
            checkSymbol = true;
            correctData += c;
        } else {
            checkSymbol = false;
            for (char d : allowSymbols) {
                if (c == d) {
                    correctData += c;
                    checkSymbol = true;
                    break;
                }
            }
        }
        if (!checkSymbol && c != ' ') {
            return "Invalid data!";
        }
    }
    return correctData;
}

void Polynom::divisionIntoGroups(const string& polynom) {
    string currentTerm;
    for (size_t i = 0; i < polynom.size(); ++i) {
        char c = polynom[i];
        if (c == '+' || c == '-') {
            if (!currentTerm.empty()) {
                if (currentTerm.find("xy^") != string::npos) xyPowerGroup.push_back(currentTerm);
                else if (currentTerm.find("xy") != string::npos) xyGroup.push_back(currentTerm);
                else if (currentTerm.find("x^") != string::npos) xPowerGroup.push_back(currentTerm);
                else if (currentTerm.find("y^") != string::npos) yPowerGroup.push_back(currentTerm);
                else if (currentTerm.find("x") != string::npos) xGroup.push_back(currentTerm);
                else if (currentTerm.find("y") != string::npos) yGroup.push_back(currentTerm);
                else constantGroup.push_back(currentTerm);
            }
            currentTerm = c;
        } else {
            currentTerm += c;
        }
    }

    if (!currentTerm.empty()) {
        if (currentTerm.find("xy^") != string::npos) xyPowerGroup.push_back(currentTerm);
        else if (currentTerm.find("xy") != string::npos) xyGroup.push_back(currentTerm);
        else if (currentTerm.find("x^") != string::npos) xPowerGroup.push_back(currentTerm);
        else if (currentTerm.find("y^") != string::npos) yPowerGroup.push_back(currentTerm);
        else if (currentTerm.find("x") != string::npos) xGroup.push_back(currentTerm);
        else if (currentTerm.find("y") != string::npos) yGroup.push_back(currentTerm);
        else constantGroup.push_back(currentTerm);
    }
}

void Polynom::changeSignInGroups() {
    for (auto& term : xGroup) changeSign(term);
    for (auto& term : yGroup) changeSign(term);
    for (auto& term : xPowerGroup) changeSign(term);
    for (auto& term : yPowerGroup) changeSign(term);
    for (auto& term : xyGroup) changeSign(term);
    for (auto& term : xyPowerGroup) changeSign(term);
    for (auto& term : constantGroup) changeSign(term);
}

void Polynom::changeSign(string& term) {
    if (term[0] == '+') term[0] = '-';
    else if (term[0] == '-') term[0] = '+';
    else term = "-" + term;
}

string Polynom::processSimpleGroup(const vector<string>& group, char var, char action) const {
    int sum = 0;
    for (const auto& term : group) {
        char sign = '+';
        int coefficient = 0;
        bool hasNumber = false;

        for (char ch : term) {
            if (isdigit(ch)) {
                coefficient = coefficient * 10 + (ch - '0');
                hasNumber = true;
            } else if (ch == '+' || ch == '-') {
                sign = ch;
            }
        }

        if (!hasNumber) coefficient = 1;
        if (action == '+') sum += (sign == '-') ? -coefficient : coefficient;
        else if (action == '-') sum += (sign == '-') ? coefficient : -coefficient;
    }

    string result;
    if (sum < 0) result = to_string(sum) + var + " ";
    else if (sum > 0) result = "+" + to_string(sum) + var + " ";
    return result;
}

string Polynom::processGroupWithPower(const vector<string>& group, char var1, char var2, char action, bool isPower) const {
    int sum = 0;
    for (const auto& term : group) {
        char sign = '+';
        int coefficient = 0;
        bool hasNumber = false;

        for (char ch : term) {
            if (isdigit(ch)) {
                coefficient = coefficient * 10 + (ch - '0');
                hasNumber = true;
            } else if (ch == '+' || ch == '-') {
                sign = ch;
            } else if (ch == '^') break;
        }

        if (!hasNumber) coefficient = 1;
        if (action == '+') sum += (sign == '-') ? -coefficient : coefficient;
        else if (action == '-') sum += (sign == '-') ? coefficient : -coefficient;
    }

    string result;
    if (sum != 0) {
        if (isPower && var2 != 'q') result = (sum < 0) ? to_string(sum) + var1 + var2 + "^2 " : "+" + to_string(sum) + var1 + var2 + "^2 ";
        else if (!isPower && var2 != 'q') result = (sum < 0) ? to_string(sum) + var1 + var2 + " " : "+" + to_string(sum) + var1 + var2 + " ";
        else result = (sum < 0) ? to_string(sum) + var1 + "^2 " : "+" + to_string(sum) + var1 + "^2 ";
    }
    return result;
}

string Polynom::add(const Polynom& other) const {
    if (correctData == "Invalid data!") return "Invalid data!";
    Polynom resultAdd;
    resultAdd.divisionIntoGroups(this->correctData);
    resultAdd.divisionIntoGroups(other.correctData);

    string resultString;
    int sumConstant = 0;
    for (const string& term : resultAdd.constantGroup) sumConstant += stoi(term);

    if (sumConstant != 0) resultString += (sumConstant < 0) ? to_string(sumConstant) + " " : "+" + to_string(sumConstant) + " ";
    resultString += processSimpleGroup(resultAdd.xGroup, 'x', '+');
    resultString += processSimpleGroup(resultAdd.yGroup, 'y', '+');
    resultString += processGroupWithPower(resultAdd.xPowerGroup, 'x', 'q', '+', true);
    resultString += processGroupWithPower(resultAdd.yPowerGroup, 'y', 'q', '+', true);
    resultString += processGroupWithPower(resultAdd.xyGroup, 'x', 'y', '+', false);
    resultString += processGroupWithPower(resultAdd.xyPowerGroup, 'x', 'y', '+', true);

    if (resultString.back() == ' ') resultString.pop_back();
    return resultString;
}

string Polynom::subtract(const Polynom& other) const {
    Polynom subtract, resultSubtract;
    subtract.divisionIntoGroups(other.correctData);
    subtract.changeSignInGroups();
    resultSubtract.divisionIntoGroups(this->correctData);

    resultSubtract.constantGroup.insert(resultSubtract.constantGroup.end(), subtract.constantGroup.begin(), subtract.constantGroup.end());
    resultSubtract.xGroup.insert(resultSubtract.xGroup.end(), subtract.xGroup.begin(), subtract.xGroup.end());
    resultSubtract.yGroup.insert(resultSubtract.yGroup.end(), subtract.yGroup.begin(), subtract.yGroup.end());
    resultSubtract.xPowerGroup.insert(resultSubtract.xPowerGroup.end(), subtract.xPowerGroup.begin(), subtract.xPowerGroup.end());
    resultSubtract.yPowerGroup.insert(resultSubtract.yPowerGroup.end(), subtract.yPowerGroup.begin(), subtract.yPowerGroup.end());
    resultSubtract.xyGroup.insert(resultSubtract.xyGroup.end(), subtract.xyGroup.begin(), subtract.xyGroup.end());
    resultSubtract.xyPowerGroup.insert(resultSubtract.xyPowerGroup.end(), subtract.xyPowerGroup.begin(), subtract.xyPowerGroup.end());

    string resultString;
    int sumConstant = 0;
    for (const string& term : resultSubtract.constantGroup) sumConstant += stoi(term);
    if (sumConstant != 0) resultString += (sumConstant < 0) ? to_string(sumConstant) + " " : "+" + to_string(sumConstant) + " ";
    resultString += processSimpleGroup(resultSubtract.xGroup, 'x', '+');
    resultString += processSimpleGroup(resultSubtract.yGroup, 'y', '+');
    resultString += processGroupWithPower(resultSubtract.xPowerGroup, 'x', 'q', '+', true);
    resultString += processGroupWithPower(resultSubtract.yPowerGroup, 'y', 'q', '+', true);
    resultString += processGroupWithPower(resultSubtract.xyGroup, 'x', 'y', '+', false);
    resultString += processGroupWithPower(resultSubtract.xyPowerGroup, 'x', 'y', '+', true);

    if (resultString.back() == ' ') resultString.pop_back();
    return resultString;
}

string Polynom::multiply(const Polynom& other) const {
    Polynom result;
    for (const auto& term1 : xGroup) {
        for (const auto& term2 : other.xGroup) result.xPowerGroup.push_back(multiplyTerms(term1, term2, 'x', true));
    }
    for (const auto& term1 : xGroup) {
        for (const auto& term2 : other.constantGroup) result.xGroup.push_back(multiplyTerms(term1, term2, 'x', false));
    }
    for (const auto& term1 : constantGroup) {
        for (const auto& term2 : other.constantGroup) result.constantGroup.push_back(multiplyTerms(term1, term2, ' ', false));
    }

    string resultString;
    resultString += processGroupWithPower(result.xPowerGroup, 'x', 'q', '+', true);
    resultString += processSimpleGroup(result.xGroup, 'x', '+');
    resultString += processSimpleGroup(result.constantGroup, ' ', '+');

    if (resultString.back() == ' ') resultString.pop_back();
    return resultString;
}

string Polynom::multiplyTerms(const string& term1, const string& term2, char var, bool isPower) const {
    int coef1 = extractCoefficient(term1);
    int coef2 = extractCoefficient(term2);
    int resultCoef = coef1 * coef2;

    if (isPower) return to_string(resultCoef) + var + "^2";
    else if (var == ' ') return to_string(resultCoef);
    else return to_string(resultCoef) + var;
}

int Polynom::extractCoefficient(const string& term) const {
    int coefficient = 0;
    bool negative = false;
    for (char ch : term) {
        if (ch == '-') negative = true;
        else if (isdigit(ch)) coefficient = coefficient * 10 + (ch - '0');
    }
    coefficient = coefficient == 0 ? 1 : coefficient;
    return negative ? -coefficient : coefficient;
}

string solutionPolynomials(const Polynom& value1, char action, const Polynom& value2) {
    if (action == '+') return value1.add(value2);
    else if (action == '-') return value1.subtract(value2);
    else if (action == '*') return value1.multiply(value2);
    return "Invalid operation!";
}
