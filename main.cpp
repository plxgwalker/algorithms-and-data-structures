#include "QuickSort.h"

int main()
{
	int arr_size = 0;
	int* arr = new int[arr_size];
	int choice = 1;

	while (choice != 0)
	{
		cout << "\n1 - QuickSort" << endl;
		cout << "2 - RandomizedQuickSort" << endl;
		cout << "3 - RandomizedSelect" << endl;
		cout << "4 - RandomizedSelect + min element" << endl;
		cout << "5 - RandomizedSelect + max element" << endl;
		cout << "6 - RandomizedSelect + mediana" << endl;
		cout << "0 - Exit" << endl;

		cout << "Your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "\nArray size: ";
			cin >> arr_size;
			input(arr, arr_size);
			QuickSort(arr, 0, arr_size - 1);
			cout << "\nSorted array: ";
			printArr(arr, arr_size);
			break;
		case 2:
			cout << "\nArray size: ";
			cin >> arr_size;
			input(arr, arr_size);
			RandomizedQuickSort(arr, 0, arr_size - 1);
			cout << "\nSorted array: ";
			printArr(arr, arr_size);
			cout << endl;
			break;
		case 3:
			cout << "\nArray size: ";
			cin >> arr_size;
			input(arr, arr_size);
			RandomizedSelect(arr, 0, arr_size - 1, 0);
			cout << "\nSorted array: ";
			printArr(arr, arr_size);
			cout << endl;
			break;
		case 4:
			cout << "\nArray size: ";
			cin >> arr_size;
			input(arr, arr_size);
			cout << "\nMin element: " << RandomizedSelect(arr, 0, arr_size - 1, 0) << endl;
			cout << "Sorted array: ";
			printArr(arr, arr_size);
			cout << endl;
			break;
		case 5:
			cout << "\nArray size: ";
			cin >> arr_size;
			input(arr, arr_size);
			cout << "\nMax element: " << RandomizedSelect(arr, 0, arr_size - 1, arr_size) << endl;
			cout << "Sorted array: ";
			printArr(arr, arr_size);
			cout << endl;
			break;
		case 6:
			cout << "\nArray size: ";
			cin >> arr_size;
			input(arr, arr_size);
			if (arr_size % 2 == 0) {
				cout << "\nMediana: " << RandomizedSelect(arr, 0, arr_size - 1, arr_size / 2) << " "
					 << RandomizedSelect(arr, 0, arr_size - 1, (arr_size / 2) + 1) << endl;
			}
			else {
				cout << "\nMediana: " << RandomizedSelect(arr, 0, arr_size - 1, (arr_size / 2) + 1) << endl;
			}
			cout << "Sorted array: ";
			printArr(arr, arr_size);
			cout << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}