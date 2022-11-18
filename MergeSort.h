#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
using namespace std;

void merge(int arr[], int p, int q, int r);
void mergeSort(int arr[], int p, int r);
void printArr(int arr[], int size);
void input(int arr[], int arr_size);
int check_user_value();
int check_array_size();
bool contains_non_alpha(string& str);
bool contains_special_symbols(string& str);