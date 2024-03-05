#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::atoi;

void selection(int* arr, int size); // O(n²)

void bubble(int* arr, int size); // O(n²)

void merge(int* arr, int size); // O(nlogn)

void print_arr(int* arr, int size);

int main(int argc, char* argv[]) {

    if (argc <= 1) {
        cout << "USAGE: " << argv[0] << "<num1> <num2> ... <numN>" << endl;
        return 1;
    }

    int values_1[argc - 1], values_2[argc - 1], values_3[argc - 1];

    for (int i = 0; i < argc - 1; i++) {
        values_1[i] = atoi(argv[i + 1]);
        values_2[i] = atoi(argv[i + 1]);
        values_3[i] = atoi(argv[i + 1]);
    }

    selection(values_1, argc -  1);

    cout << ">> Selection_Sort: ";
    print_arr(values_1, argc - 1);

    bubble(values_2, argc - 1);

    cout << ">> Bubble_Sort: ";
    print_arr(values_2, argc - 1);

    //int* arr_merge = merge(values, argc - 1);

    //cout << ">> Merge_Sort: ";
    //print_arr(arr_merge, argc - 1);

    return 0;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selection(int* arr, int size) {    
    for (int i = 0; i < size; i++) {
        int min = arr[i], pos = i;

        for (int j = i; j < size; j++) {
            if (arr[j] < min) {
                min = arr[j];
                pos = j;
            }
        }

        swap(&arr[i], &arr[pos]);
    }
}

void bubble(int* arr, int size) {
    int swaped;

    for (int i = 0; i < size; i++) {
        swaped = 0;

        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swaped = 1;
            }
        }

        if (swaped == 0) break;
    }
}

void merge(int* arr, int size) {
    // A fazer...
}

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}