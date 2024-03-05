#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::atoi;

void pyramid(int number); // without recursion

void pyramid_recursion(int number); // with recursion

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cout << "USAGE: " << argv[0] << " <num>" << endl;
        return 1;
    }

    // pyramid(atoi(argv[1]));

    pyramid_recursion(atoi(argv[1]));

    return 0;
}

void pyramid(int number) {
    if (number < 0) {
        cout << "Sorry, negative number is invalid!" << endl;
    }

    for (int i = 0; i < number; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "#";
        }

        cout << endl;
    }
}

void pyramid_recursion(int number) {
    if (number < 0) {
        cout << "Sorry, negative number is invalid!" << endl;
    }

    if (number == 0) {
        
    } else {
        pyramid_recursion(number - 1);

        for (int i = 0; i < number; i++) {
            cout << "#";
        }

        cout << endl;
    }
}