/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include "console.h"
#include "hashset.h"
#include "set.h"
#include "timer.h"
#include "vector.h"
using namespace std;

// possible chices: VECTOR, SET, HASHSET
// res/mobydick.txt:    HASHSET 463653 ms
//                      SET     683239 ms
//                      VECTOR  177467 ms

// res/smallmoby.txt:   HASHSET 168673 ms
//                      SET     168673 ms
//                      VECTOR  55886 ms
#define VECTOR

bool contains(const Vector<string>& v, const string& s);
bool contains(const Set<string>& v, const string& s);
bool contains(const HashSet<string>& v, const string& s);

void wordCount(const string& filename);

int main()
{
    wordCount("res/smallmoby.txt");
    return 0;
}

void wordCount(const string &filename) {
    cout << "Reading " << filename << " ..." << endl;
#ifdef VECTOR
    Vector<string> allwords;
#elif defined SET
    Set<string> allwords;
#elif defined HASHSET
    HashSet<string> allwords;
#endif
    Timer timer;
    timer.start();

    ifstream input;
    string word;
    int wordCount = 0;
    input.open(filename);

    while (input >> word) {
        wordCount++;
        if (wordCount % 10000 == 0) {
                    cout << wordCount << "..." << endl;
        }
        if (!contains(allwords, word)) {
            allwords.add(word);
        }
    }

    cout << "Total word: " << wordCount << ", unique word: " << allwords.size()
         << endl;
    cout << "Took " << timer.stop() << " ms." << endl;
}

bool contains(const Vector<string> &v, const string &s) {
    for (string word : v) {
        if (s == word) {
            return true;
        }
    }
    return false;
}

bool contains(const Set<string>& v, const string& s) {
    for (string word : v) {
        if (s == word) {
            return true;
        }
    }
    return false;
}

bool contains(const HashSet<string>& v, const string& s) {
    for (string word : v) {
        if (s == word) {
            return true;
        }
    }
    return false;
}


