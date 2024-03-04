#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cerr;
using std::cin;

int binsearch(int* arr, int size, int x); // O(log n)

int linsearch(int* arr, int size, int x); // O(n)

int main(int argc, char* argv[]) {

    if (argc <= 1) {
        cerr << "USAGE: " << argv[0] << " <num1> <num2> ... <numN>" << endl;
        return 1;
    }

    int values[argc - 1];

    for (int i = 0; i < argc - 1; i++) {
        values[i] = atoi(argv[i + 1]);
    }

    int number;

    cout << "What's the number that you are find: "; cin >> number;

    int result_lin = linsearch(values, argc - 1, number);

    int result_bin = binsearch(values, argc - 1, number);

    if (result_lin == -1) {
        cout << "The value " << number << " isn't finded on the array." << endl;
    } else {
        cout << ">> linear search: " << result_lin << endl;
    }

    if (result_bin == -1) {
        cout << "The value " << number << " isn't finded on the array." << endl;
    } else {
        cout << ">> binary search: " << result_bin << endl;
    }

    return 0;

}

int binsearch(int* arr, int size, int x) {

    int low = 0, high = size - 1;
    int k;

    while (low <= high) {

        k = (low + high) / 2;

        if (arr[k] == x) {
            return k;
        } else if (arr[k] > x) {
            high = k - 1;
        } else {
            low = k + 1;
        }
    }
    
    return -1;

}

int linsearch(int* arr, int size, int x) {
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) return i;
    }

    return -1;

}
