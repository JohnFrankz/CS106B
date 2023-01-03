#include <iomanip>
#include "console.h"
#include "simpio.h"
#include "vector.h"
using namespace std;


int main() {
    Vector<int> magic;
    magic.add(4);
    magic.add(8);
    magic.add(15);
    magic.add(16);

    Vector<int> magic1;
    magic1.add(4);
    magic1.add(8);
    magic1.add(15);
    magic1.add(17);

    cout << "use []: " << magic[2] << endl;
    cout << "use get: " << magic.get(2) << endl;

//    for (int i = 0; i < magic.size(); i++) {
//        cout << magic[i] << setw(4);
//    }
    for (int value : magic) {
        cout << value << setw(4);
    }
    cout << endl;

    cout << "is magic equal magic1: " << magic.equals(magic1) << endl;
    return 0;
}
