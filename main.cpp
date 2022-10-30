#include "MergeSort.h"

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArr(arr, arr_size);

    mergeSort(arr, 0, arr_size);

    cout << "\nSorted array is \n";
    printArr(arr, arr_size);
    return 0;
}