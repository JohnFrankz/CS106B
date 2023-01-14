#include "console.h"
#include "queue.h"
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

int main() {
    // slide 7
    string sentence = "hope is what defines humanity";
    string word;
    Stack<string> wordStack;

    cout << "Original sentence: " << sentence << endl;

    for (char c : sentence) {
        if (c == SPACE) {
            wordStack.push(word);
            word = ""; // reset
        } else {
            word += c;
        }
    }
    if (word != "") {
        wordStack.push(word);
    }

    cout << "     New sentence: ";
    while (!wordStack.isEmpty()) {
        word = wordStack.pop();
        cout << word << SPACE;
    }
    cout << endl;

    // slide 10

    Queue<int> q;
    q.enqueue(42);
    q.enqueue(-3);
    q.enqueue(17);

    cout << q.peek() << endl;
    cout << q.dequeue() << endl << endl;

    // slide
    Queue<int> queue;
    // produce: {1, 2, 3, 4, 5, 6}
    for (int i = 1; i <= 6; i++) {
        queue.enqueue(i);
    }
    for (int i = 0; i < queue.size(); i++) {
        cout << queue.dequeue() << " ";
    }
    cout << queue.toString() << "  size " << queue.size() << endl;

    // slide 13: queue idiom #1
    Queue<int> queueIdiom1;
    // produce: {1, 2, 3, 4, 5, 6}
    for (int i = 1; i <= 6; i++) {
        queueIdiom1.enqueue(i);
    }
    while (!queueIdiom1.isEmpty()) {
        cout << queueIdiom1.dequeue() << " ";
    }
    cout << queueIdiom1.toString() << "  size " << queueIdiom1.size() << endl;

    // slide 14: queue idiom #2
    Queue<int> queueIdiom2;
    for (int i = 0; i < 6; i++) {
        queueIdiom2.enqueue(i + 1);
    }

    int origQSize = queueIdiom2.size();
    for (int i = 0; i < origQSize; i++) {
        int value = queueIdiom2.dequeue();
        cout << value << " ";
        // re-enqueue even values
        if (value % 2 == 0) {
            queueIdiom2.enqueue(value);
        }
    }
    cout << endl;
    cout << queueIdiom2 << endl;

    // slide 17: postfix example
    string expression;
    double answer;
    do {
        expression =
            getLine("Please enter a postfix expression (blank to quit): ");
        if (expression == "") {
            break;
        }
        answer = parsePostfix(expression);
        cout << "The answer is: " << answer << endl << endl;
    } while (true);

    return 0;
}

string getNextToken(string &expression) {
    // pull out the substring up to the first space
    // and return the token, removing it from the expression

    string token;
    int sepLoc = expression.find(SEPARATOR);
    if (sepLoc != (int)string::npos) {
        token = expression.substr(0, sepLoc);
        expression = expression.substr(sepLoc + 1, expression.size() - sepLoc);
        return token;
    } else {
        token = expression;
        expression = "";
        return token;
    }
}

double parsePostfix(string expression) {
    Stack<double> s;
    string nextToken;

    while (expression != "") {
        // gets the next token and removes it from expression
        nextToken = getNextToken(expression);
        if (OPERATORS.find(nextToken) == string::npos) {
            // we have a number
            double operand = stringToDouble(nextToken);
            s.push(operand);
        } else {
            // we have an operator
            char op = stringToChar(nextToken);
            performCalculation(s, op);
        }
    }
    return s.pop();
}

void performCalculation(Stack<double> &s, char op) {
    double result;
    double operand2 = s.pop(); // LIFO!
    double operand1 = s.pop();
    switch (op) {
    case '+':
        result = operand1 + operand2;
        break;
    case '-':
        result = operand1 - operand2;
        break;
        // allow "*" or "x" for times
    case '*':
    case 'x':
        result = operand1 * operand2;
        break;
    case '/':
        result = operand1 / operand2;
        break;
    }
    s.push(result);
}
