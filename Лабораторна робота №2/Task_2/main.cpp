#include "polynom.h"
#include <iostream>


int main() {

    Polynom polynom1("-3x^2 + 3xy^2 - 30x - 40 - 5y - 3y^2 - 15xy");
    Polynom polynom2("x^2 - 4x^2 + 5x - 5 - 35 + y + 2y^2 + 10xy - 5xy^2");
    Polynom polynom3("2x -x");
    Polynom polynom4("x + 1");

    string resultAdd = solutionPolynomials(polynom3, '+', polynom4);
    cout << "result add : " << resultAdd << endl;
    string resultMultiply = solutionPolynomials(polynom3, '*', polynom4);
    cout << "result multiply : " << resultMultiply << endl;
    string resultSubtract = solutionPolynomials(polynom3, '-', polynom4);
    cout << "result subtruct : " << resultSubtract << endl;

    return 0;
}
