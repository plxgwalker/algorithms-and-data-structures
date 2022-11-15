#include "MergeSort.h"

void merge(int arr[], int p, int q, int r)
{ 
    // Create L ← A[p..q] and R ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    auto* L = new int[n1];
    auto* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or R, pick larger among
    // elements L and R and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or R,
    // pick up the remaining elements and put in arr[p..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

void input(int arr[], int arr_size)
{
    cout << "Initialize an array: ";
    for (int i = 0; i < arr_size; i++)
    {
        cin >> arr[i];
    }
}
