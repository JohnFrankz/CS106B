#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string promptUserForFile(ifstream &infile, string prompt = "");

int main(int argc, char* argv[]) {
    ifstream infile; 
    promptUserForFile(infile, "Input file: ");
    char ch;
    while (infile.get(ch)) {
        cout.put(ch);
    }
    infile.close();
    return 0;
}

/**
 * Function: promptUserForFile
 * Usage:
 *
 */
string promptUserForFile(ifstream &infile, string prompt) {
    while (true) {
        cout << prompt;
        string filename;
        getline(cin, filename);
        infile.open(filename.c_str());

        if (!infile.fail()) {
            return filename;
        }
        infile.clear();
        cout << "Unable to open that file, Try again." << endl;
        if (prompt == "") {
            prompt = "Input file: ";
        }
    }
}
