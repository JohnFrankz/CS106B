/*
 * CS106B Section Handout Test Harness: Section 1
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Trip Master and Nick
 * Bowman for CS106B Spring 2020.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */
#include <iostream>
#include "grid.h"
#include "SimpleTest.h"
#include "vector.h"
#include "filelib.h"
using namespace std;

bool isNumber(string str) {
    if (str.length() < 1) {
        return false;
    }

    if (str[0] == '-') {
        str = str.substr(1);
    }

    for (char ch : str) {
        if (!isdigit(ch)) {
            return false;
        }
    }

    return true;
}

/*
 * Sum Numbers (Code Write)
 * ----------------------------------
 * Write a program to read through a given file and sum
 * all of the numbers in the file. You can assume that numbers
 * will be composed entirely of numerical digits, optionally
 * preceded by a single negative sign.
 */
int sumNumbers(string filename) {
    Vector<string> lines;
    ifstream infile;
    int sum = 0;

    if (!openFile(infile, filename)) {
        return 0;
    }
    readEntireFile(infile, lines);
    for (string line : lines) {
        Vector<string> numbers = stringSplit(line, " ");
        for (string number : numbers) {
            if (isNumber(number)) {
                sum += stringToInteger(number);
            }
        }
    }
    return sum;
}


/* * * * * Provided Tests Below This Point * * * * */
PROVIDED_TEST("given file in handout") {
    EXPECT_EQUAL(sumNumbers("res/numbers.txt"), 42);
}

PROVIDED_TEST("Nonexistent file should sum to zero") {
    EXPECT_EQUAL(sumNumbers("nonexistent_filename"), 0);
}

