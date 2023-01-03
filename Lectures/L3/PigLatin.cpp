#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

string lineToPigLatin(string line);
string wordToPigLatin(string word);
int findFirstVowel(string word);
bool isVowel(char ch);

int main(int argc, char* argv[]) {
    cout << "This is program translates English to pig Latin." << endl;
    string line;
    cout << "Enter English text: ";
    getline(cin, line);
    string translation = lineToPigLatin(line);
    cout << "Pig Latin output: " << translation << endl;
    return 0;
}

string lineToPigLatin(string line) {
    string result;
    int start = -1;
    for (int i = 0; i < line.length(); i++) {
        char ch = line[i];
        if (isalpha(ch)) {
            if (start == -1) {
                start = i;
            }
        } else {
            if (start >= 0) {
                result += wordToPigLatin(line.substr(start, i - start));
                start = -1;
            }
            result += ch;
        }
    }

    if (start >= 0) {
        result += wordToPigLatin(line.substr(start));
    }
    return result;
}

string wordToPigLatin(string word) {
    int vp = findFirstVowel(word);
    if (vp == -1) {
        return word;
    }

    if (vp == 0) {
        return word + "way";
    }

    string head = word.substr(0, vp);
    string tail = word.substr(vp);
    return tail + head + "ay";
}

int findFirstVowel(string word) {
/*   for (int i = 0; i < word.length(); i++) {
        if (isVowel(word[i])) {
            return i;
        }
    }
    return -1; */
    const string vowels = "aeiou";
    return word.find_first_of(vowels);

}

bool isVowel(char ch) {
    string vowels = "aeiou";
    return vowels.find(ch) != string::npos;
}
