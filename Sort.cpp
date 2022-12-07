#include "Sort.h"

void CountingSort(int A[], int k, int arr_size)
{
    int* B = new int[arr_size];
	int* C = new int[k];

	for (int i = 0; i < k; i++) C[i] = 0;
    for (int j = 0; j < arr_size; j++) C[A[j]] += 1;
    for (int i = 1; i < k; i++) C[i] = C[i] + C[i - 1];
    for (int j = arr_size - 1; j >= 0; j--)
    {
        B[C[A[j]] - 1] = A[j];
        C[A[j]] -= 1;
    }

    for (int i = 0; i < arr_size; i++) A[i] = B[i];
}

void RedixCountSort(int A[], int s, int d)
{
    int* arrB = new int[s];
    int s2 = max_value(A, s);
    int* arrC = new int[s2];

    for (int i = 0; i < 10; i++) arrC[i] = 0;
    for (int j = 0; j < s; j++) arrC[(A[j] / d) % 10]++;
    for (int i = 1; i < 10; i++) arrC[i] = arrC[i] + arrC[i - 1];
    for (int j = s - 1; j >= 0; j--) 
    {
        arrB[arrC[(A[j] / d) % 10] - 1] = A[j];
        arrC[(A[j] / d) % 10]--;
    }

    for (int i = 0; i < s; i++) A[i] = arrB[i];
}

void RedixSort(int arr[], int arr_size)
{
    int max = max_value(arr, arr_size);

    for (int i = 1; max / i > 0; i *= 10)
    {
        RedixCountSort(arr, arr_size, i);
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int max_value(int arr[], int arr_size)
{
    int max = arr[0];

    for (int i = 1; i < arr_size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

void input(int arr[], int arr_size)
{
    int temp = 0;
    cout << "Initialize an array: " << endl;

    for (int i = 0; i < arr_size; i++)
    {
        temp = check_user_value();
        arr[i] = temp;
    }
}

int check_user_value()
{
    string user_value = "";
    string reply_empty_value = "Empty value for element: ";
    string reply_not_digit_value = "Value is not digit: ";

    getline(cin, user_value);

    while (user_value.empty() || cin.fail() || stoi(user_value) < 0 || stoi(user_value) > 9)
    {
        if (user_value.empty())
        {
            cout << reply_empty_value << endl;
        }
        else if (stoi(user_value) < 0)
        {
            cout << reply_not_digit_value << endl;
        }
        else if (stoi(user_value) > 9)
        {
            cout << reply_not_digit_value << endl;
        }

        getline(cin, user_value);
    }

    return stoi(user_value);
}

void input_redix(int arr[], int arr_size)
{
    int temp = 0;
    cout << "Initialize an array: " << endl;

    for (int i = 0; i < arr_size; i++)
    {
        temp = check_user_value_redix();
        arr[i] = temp;
    }
}

int check_user_value_redix()
{
    string user_value = "";
    string reply_empty_value = "Empty value for element: ";
    string reply_not_digit_value = "Value is not digit: ";

    getline(cin, user_value);

    while (user_value.empty() || cin.fail() || stoi(user_value) < 0)
    {
        if (user_value.empty())
        {
            cout << reply_empty_value << endl;
        }
        else if (stoi(user_value) < 0)
        {
            cout << reply_not_digit_value << endl;
        }

        getline(cin, user_value);
    }

    return stoi(user_value);
}

int check_array_size()
{
    string user_value = "";
    string reply_empty_value = "Empty value for array size: ";
    string reply_negative_value = "Negative value for array size: ";

    cout << "Insert array size: ";
    getline(cin, user_value);

    while (user_value.empty() || stoi(user_value) <= 1)
    {
        if (user_value.empty())
        {
            cout << reply_empty_value << endl;
        }
        else if (stoi(user_value) <= 1)
        {
            cout << reply_negative_value << endl;
        }

        getline(cin, user_value);
    }

    return stoi(user_value);
}
