/*
 * TODO: remove and replace this file header comment
 * This is a .cpp file you will edit and turn in.
 * Remove starter comments and add your own
 * comments on each function and on complex code sections.
 */
#include <cctype>
#include <fstream>
#include <string>
#include "console.h"
#include "strlib.h"
#include "filelib.h"
#include "simpio.h"
#include "vector.h"
#include "map.h"
#include "set.h"
#include <cctype>
#include "SimpleTest.h" // IWYU pragma: keep (needed to quiet spurious warning)
using namespace std;

const int MAX_ENCODE_DIGIT = 6;
const Map<int, Set<char>> ENCODE_TABLE = {
    {0, {'a', 'e', 'i', 'o', 'u', 'h', 'w', 'y'}},
    {1, {'b', 'f', 'p', 'v'}},
    {2, {'c', 'g', 'j', 'k', 'q', 's', 'x', 'z'}},
    {3, {'d', 't'}},
    {4, {'l'}},
    {5, {'m', 'n'}},
    {6, {'r'}},
};
/* This function is intended to return a string which
 * includes only the letter characters from the original
 * (all non-letter characters are excluded)
 *
 * WARNING: The provided code is buggy!
 *
 * Use test cases to identify which inputs to this function
 * are incorrectly handled. Then, remove this comment and
 * replace it with a description of the bug you fixed.
 */
string lettersOnly(string s) {
    if (s.length() < 1) {
        return "";
    }
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            result += s[i];
        }
    }
    return result;
}

char encodeLitter(const char ch) {
    for (int digit : ENCODE_TABLE) {
        if (ENCODE_TABLE[digit].contains(tolower(ch))) {
            return digit + '0';
        }
    }
    return NULL;
}

void deduplication(string &s) {
    for (int i = 0; i < s.length() - 1; ) {
        if (s[i] == s[i + 1]) {
            s.erase(i + 1, 1);
        } else {
            i++;
        }
    }
}

void removeZero(string &s) {
    for (int i = 0; i < s.length();) {
        if (s[i] == '0') {
            s.erase(i, 1);
        } else {
            i++;
        }
    }
}

void encode(string &s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = encodeLitter(s[i]);
    }
}

void ctrlLength(string &s) {
    if (s.length() > 4) {
        s.erase(4);
    } else if (s.length() < 4) {
        s += string(4 - s.length(), '0');
    }
}

/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
string soundex(string s) {
    /* TODO: Fill in this function. */
    string letterOnlyStr = lettersOnly(s);
    if (letterOnlyStr.length() < 1) {
        return "";
    }

    string firstLetter = toUpperCase(string(1, letterOnlyStr[0]));
    encode(letterOnlyStr);
    deduplication(letterOnlyStr);
    letterOnlyStr[0] = firstLetter[0];
    removeZero(letterOnlyStr);
    ctrlLength(letterOnlyStr);
    return letterOnlyStr;
}


/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
void soundexSearch(string filepath) {
    // This provided code opens the specified file
    // and reads the lines into a vector of strings
    ifstream in;
    Vector<string> allNames;

    if (openFile(in, filepath)) {
        readEntireFile(in, allNames);
    }
    cout << "Read file " << filepath << ", "
         << allNames.size() << " names found." << endl;

    // The names read from file are now stored in Vector allNames

    /* TODO: Fill in the remainder of this function. */
}


/* * * * * * Test Cases * * * * * */


PROVIDED_TEST("Test exclude of punctuation, digits, and spaces") {
    string s = "O'Hara";
    string result = lettersOnly(s);
    EXPECT_EQUAL(result, "OHara");
    s = "Planet9";
    result = lettersOnly(s);
    EXPECT_EQUAL(result, "Planet");
    s = "tl dr";
    result = lettersOnly(s);
    EXPECT_EQUAL(result, "tldr");
}


PROVIDED_TEST("Sample inputs from handout") {
    EXPECT_EQUAL(soundex("Curie"), "C600");
    EXPECT_EQUAL(soundex("O'Conner"), "O256");
}

PROVIDED_TEST("hanrahan is in lowercase") {
    EXPECT_EQUAL(soundex("hanrahan"), "H565");
}

PROVIDED_TEST("DRELL is in uppercase") {
    EXPECT_EQUAL(soundex("DRELL"), "D640");
}

PROVIDED_TEST("Liu has to be padded with zeros") {
    EXPECT_EQUAL(soundex("Liu"), "L000");
}

PROVIDED_TEST("Tessier-Lavigne has a hyphen") {
    EXPECT_EQUAL(soundex("Tessier-Lavigne"), "T264");
}

PROVIDED_TEST("Au consists of only vowels") {
    EXPECT_EQUAL(soundex("Au"), "A000");
}

PROVIDED_TEST("Egilsdottir is long and starts with a vowel") {
    EXPECT_EQUAL(soundex("Egilsdottir"), "E242");
}

PROVIDED_TEST("Jackson has three adjcaent duplicate codes") {
    EXPECT_EQUAL(soundex("Jackson"), "J250");
}

PROVIDED_TEST("Schwarz begins with a pair of duplicate codes") {
    EXPECT_EQUAL(soundex("Schwarz"), "S620");
}

PROVIDED_TEST("Van Niekerk has a space between repeated n's") {
    EXPECT_EQUAL(soundex("Van Niekerk"), "V526");
}

PROVIDED_TEST("Wharton begins with Wh") {
    EXPECT_EQUAL(soundex("Wharton"), "W635");
}

PROVIDED_TEST("Ashcraft is not a special case") {
    // Some versions of Soundex make special case for consecutive codes split by hw
    // We do not make this special case, just treat same as codes split by vowel
    EXPECT_EQUAL(soundex("Ashcraft"), "A226");
}

// TODO: add your test cases here

STUDENT_TEST("test empty string or a string composed of only non-letter characters"
             "or first character is non-letter") {
    string s = "";
    string result = lettersOnly(s);
    EXPECT_EQUAL(result, "");
    s = "789./-";
    result = lettersOnly(s);
    EXPECT_EQUAL(result, "");
    s = "7tl dr";
    result = lettersOnly(s);
    EXPECT_EQUAL(result, "tldr");

 }
