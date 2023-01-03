/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "grid.h"
using namespace std;

void printGrid(Grid<char> &grid);
void nameDiamond(string s);

int main()
{
    string s = "MARTY";
    nameDiamond(s);

    return 0;
}

void printGrid(Grid<char> &grid) {
    for (int r = 0; r < grid.numRows(); r++) {
        for(int c = 0; c < grid.numCols(); c++) {
                    cout << grid[r][c];
                }
                cout << endl;
    }
}

void nameDiamond(string s) {
//    for (int end = 0; end < s.length(); end++) {
//        for (int j = 0; j <= end; j++) {
//            cout << s[j];
//        }
//        cout << endl;
//    }
    for (int i = 0; i < s.length(); i++) {
        cout << s.substr(0, i + 1) << endl;
    }

    for (int i = 1; i < s.length(); i++) {
        for (int j = 0; j < i; j ++) {
            cout << " ";
        }
        cout << s.substr(i, s.length()) << endl;
    }
}
