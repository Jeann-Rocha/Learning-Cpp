#include <iostream>
#include <cstdlib>
#include <cstdbool>

using std::cout;
using std::endl;
using std::atoi;

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

void bubble(int* arr, int size) {
    bool is_sorted;
    for (int i = 0; i < size - 1; i++) {
        is_sorted = true;
        if (arr[i] > arr[i + 1]) {
            swap(&arr[i], &arr[i + 1]);
            is_sorted = false;
        }

        if (is_sorted) break;
    }
}

int main(int argc, char* argv[]) {

    if (argc == 1) {
        cout << "USAGE: " << argv[0] << " <num1> <num2> ... <numN>" << endl;
        return 1;
    }

    int size = argc - 1;
    int values[size];

    for (int i = 0; i < size; i++)
        values[i] = atoi(argv[i + 1]);

    print_arr(values, size);

    bubble(values, size);

    print_arr(values, size);

    return 0;

}