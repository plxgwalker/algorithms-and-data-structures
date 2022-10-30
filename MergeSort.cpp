#include "MergeSort.h"

void merge(int arr[], int p, int q, int  r)
{
    int const n1 = q - p + 1;
    int const n2 = r - q;

    int *L = new int[n1 + 1];
    int *R = new int[n2 + 1];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[q + j + 1];
    }

    int i = 1;
    int j = 1;
    int k = 0;

    for (int k = p; i < n1 && j < n2; k++)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i++];
        }
        else
        {
            arr[k] = R[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;

        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}