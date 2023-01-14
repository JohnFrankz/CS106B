/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "stack.h"
#include "strlib.h"
#include <iostream>

using namespace std;

const char SPACE = ' ';
const string OPERATORS = "+-*x/";
const string SEPARATOR = " ";

double parsePostfix(string expression);
string getNextToken(string &expression);
void performCalculation(Stack<double> &s, char op);

int main()
{
    string expression;
    double answer;
    do {
        expression =
                getLine("Plese enter a postfix expression (blank to quit): ");
        if (expression == "") {
            break;
        }
        answer = parsePostfix(expression);
        cout << "The answer is: " << answer << endl;
    } while (true);

    return 0;
}

double parsePostfix(string expression) {
    Stack<double> s;
    string nextToken;

    while (expression != "") {
        // get the next token and removes it from expression
        nextToken = getNextToken(expression);
        if (OPERATORS.find(nextToken) == string::npos) {
            double operand = stringToDouble(nextToken);
            s.push(operand);
        } else {
            char op = stringToChar(nextToken);
            performCalculation(s, op);
        }
    }
    return s.pop();
}

string getNextToken(string &expression) {
    string token;
    int sepLoc = expression.find(SEPARATOR);
    if (sepLoc != (int) string::npos) {
        token = expression.substr(0, sepLoc);
        expression = expression.substr(sepLoc + 1, expression.size() - 1);
        return token;
    } else {
        token = expression;
        expression = "";
        return token;
    }
}

void performCalculation(Stack<double> &s, char op) {
    double result;
    double operand2 = s.pop();
    double operand1 = s.pop();

    switch (op) {
    case '+':
        result = operand1 + operand2;
        break;
    case '-':
        result = operand1 - operand2;
        break;
    case 'x':
    case '*':
        result = operand1 * operand2;
        break;
    case '/':
        result = operand1 / operand2;
        break;
    }
    s.push(result);
}
