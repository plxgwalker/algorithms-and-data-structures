#include "Sort.h"

int main()
{
    int arr_size = 0;
    int* arr = new int[arr_size];

    int choice = 0;
    cout << "Enter choice: ";
    cin >> choice;

   switch (choice)
   {
   case 1:
        arr_size = check_array_size();
        input(arr, arr_size);

        cout << "\nGiven arrays: ";
        printArr(arr, arr_size);

        CountingSort(arr, max_value(arr, arr_size) + 1, arr_size);

        cout << "\nSorted array by CountingSort: ";
        printArr(arr, arr_size);

        break;
   case 2:
        arr_size = check_array_size();
        input_redix(arr, arr_size);

        cout << "\nGiven arrays: ";
        printArr(arr, arr_size);

        RedixSort(arr, arr_size);

        cout << "\nSorted array by CountingSortRedix: ";
        printArr(arr, arr_size);

        break;
   case 0:
        break;
   }

	return 0;
}