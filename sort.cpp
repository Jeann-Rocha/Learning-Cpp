#include <iostream>
#include <cstdlib>

using std::cout;
using std::cerr;
using std::endl;
using std::atoi;

void selection(int* arr, int size); // O(n²)

void bubble(int* arr, int size); // O(n²)

void merge(int* arr, int size); // O(nlogn)

void insertion(int* arr, int size); //

void shell(int* arr, int size); //

void quick(int* arr, int size); //

void print_arr(int* arr, int size);

int main(int argc, char* argv[]) {

    if (argc <= 1) {
        cerr << "USAGE: " << argv[0] << " <num1> <num2> ... <numN>" << endl;
        return 1;
    }

    int values_1[argc - 1], values_2[argc - 1], values_3[argc - 1];

    for (int i = 0; i < argc - 1; i++) {
        values_1[i] = atoi(argv[i + 1]);
        values_2[i] = atoi(argv[i + 1]);
        values_3[i] = atoi(argv[i + 1]);
    }

    // ---------------------------------------------------------------------

    selection(values_1, argc -  1);

    cout << ">> Selection_Sort: ";
    print_arr(values_1, argc - 1);

    // ---------------------------------------------------------------------

    bubble(values_2, argc - 1);

    cout << ">> Bubble_Sort: ";
    print_arr(values_2, argc - 1);

    // ---------------------------------------------------------------------

    //int* arr_merge = merge(values, argc - 1);

    //cout << ">> Merge_Sort: ";
    //print_arr(arr_merge, argc - 1);

    // ---------------------------------------------------------------------

    //int* arr_insertion = insertion(values, argc - 1);

    //cout << ">> Insertion_Sort: ";
    //print_arr(arr_insertion, argc - 1);

    // ---------------------------------------------------------------------

    //int* arr_shell = shell(values, argc - 1);

    //cout << ">> Shell_Sort: ";
    //print_arr(arr_shell, argc - 1);

    // ---------------------------------------------------------------------

    //int* arr_quick = quick(values, argc - 1);

    //cout << ">> Quick_Sort: ";
    //print_arr(arr_quick, argc - 1);

    // ---------------------------------------------------------------------

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

int* copy(int* arr1) {
    // A fazer...
}

void merge(int* arr, int size) {
    // A fazer...
}

int* merging(int* arr1, int* arr2, int size1, int size2) {
    // A fazer...
}

void insertion(int* arr, int size) {
    // A fazer...
}

void shell(int* arr, int size) {
    // A fazer...
}

void quick(int* arr, int size) {
    // A fazer...
}

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}