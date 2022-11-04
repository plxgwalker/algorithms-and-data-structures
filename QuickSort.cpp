#include "QuickSort.h"

void input(int arr[], int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		cin >> arr[i];
	}
}

void QuickSort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = Partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}

int Partition(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1;

	for (int j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			i += 1;
			swap(A[i], A[j]);
		}
	}

	swap(A[i + 1], A[r]);
	return i + 1;
}

void printArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

int RandomizedPartition(int A[], int p, int r)
{
	int i = rand() % r + 1;
	swap(A[i], A[r]);
	return Partition(A, p, r);
}

void RandomizedQuickSort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = RandomizedPartition(A, p, r);
		RandomizedQuickSort(A, p, q - 1);
		RandomizedQuickSort(A, p + 1, r);
	}
}

int RandomizedSelect(int A[], int p, int r, int i)
{
	if (p == r)
	{
		return A[p];
	}

	int q = RandomizedPartition(A, p, r);
	int k = q - p + 1;

	if (i == k)
	{
		return A[q];
	}

	else if (i < k)
	{
		return RandomizedSelect(A, p, q - 1, i);
	}

	else
	{
		return RandomizedSelect(A, q + 1, r, i - k);
	}
}