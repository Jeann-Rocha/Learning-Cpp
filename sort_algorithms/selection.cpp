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

void selection(int* arr, int size) {
    int min = 0;
    for (int i = 0; i < size; i++, min = i) {
        for (int j = i; j < size; j++)
            if (arr[min] > arr[j]) min = j;
        swap(&arr[i], &arr[min]);
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

    selection(values, size);

    print_arr(values, size);

    return 0;

}