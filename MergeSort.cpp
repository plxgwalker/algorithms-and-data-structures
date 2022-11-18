#include "MergeSort.h"

void merge(int arr[], int p, int q, int r)
{ 
    int n1 = q - p + 1;
    int n2 = r - q;

    auto* L = new int[n1];
    auto* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

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
    string reply_letter_value = "Value is letter: ";
    string reply_symbol_value = "Value is symbol: ";

    getline(cin, user_value);

    while (user_value.empty() || cin.fail() || contains_non_alpha(user_value) == 1 || contains_special_symbols(user_value) == 0)
    {
        if (user_value.empty())
        {
            cout << reply_empty_value << endl;
        }
        else if(contains_non_alpha(user_value) == 1)
        {
            cout << reply_letter_value << endl;
        }
        else if (contains_special_symbols(user_value) == 0)
        {
            cout << reply_symbol_value << endl;
        }

        getline(cin, user_value);
    }

    return stoi(user_value);
}

bool contains_non_alpha(string& str)
{
    return regex_match(str, regex("^[a-zA-Z]+"));
}

bool contains_special_symbols(string& str)
{
    return regex_match(str, regex("^[^<>{}\"/|;:.,~!?@#$%^=&*\\]\\\\()\\[¿§«»ω⊙¤°℃℉€¥£¢¡®©0_+]*$"));
}

int check_array_size()
{
    string user_value = ""; 
    string reply_empty_value = "Empty value for array size: ";
    string reply_negative_value = "Negative value for array size: ";

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
