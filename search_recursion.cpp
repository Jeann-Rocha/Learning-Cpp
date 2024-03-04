#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::atoi;
using std::cerr;
using std:: endl;

int binsearch(int* arr, int x, int low, int high);

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

    cout << "What's the number that you want to find: "; cin >> number;

    int result_bin = binsearch(values, number, 0, argc - 2);

    if (result_bin == -1) {
        cout << "Your number aren't finded." << endl;
    } else {
        cout << "Your number are finded in the position: " << result_bin << endl;
    }

    return 0;

}

int binsearch(int* arr, int x, int low, int high) {

    int k = (low + high) / 2;

    if (low > high) return -1;

    if (arr[k] == x) return k;

    if (arr[k] < x) return binsearch(arr, x, k + 1, high);

    if (arr[k] > x) return binsearch(arr, x, low, k - 1);

}