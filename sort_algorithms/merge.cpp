#include <iostream>
#include <cstdlib>

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

void merge(int* arr, int size) {
    // a fazer...
    if (size > 1) {
        int* arr

        merge();
        merge();
        merging()
    }

}

int* merging(int* a, int* b, int size_a, int size_b) {
    // a fazer...
    if (size_a == 0) return b;
    if (size_b == 0) return a;


    
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

    merge(values, size);

    print_arr(values, size);

    return 0;

}