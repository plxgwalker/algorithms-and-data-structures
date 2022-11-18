#include "MergeSort.h"

int main()
{
    int arr_size = 0;
    int* arr = new int[arr_size];

    cout << "Initialize array size: ";
    arr_size = check_array_size();
    input(arr, arr_size);

    cout << "\nGiven array: ";
    printArr(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array: ";
    printArr(arr, arr_size);

    return 0;
}