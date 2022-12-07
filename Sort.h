#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void input(int arr[], int arr_size);
void input_redix(int arr[], int arr_size);
void printArr(int arr[], int size);
int max_value(int arr[], int arr_size);
int check_user_value();
int check_array_size();
int check_user_value_redix();

void CountingSort(int A[], int k, int arr_size);
void RedixSort(int arr[], int arr_size);
void RedixCountSort(int A[], int s, int d);