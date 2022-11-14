#pragma once
#include <iostream>
using namespace std;

void QuickSort(int A[], int p, int r);
int Partition(int A[], int p, int r);
void input(int arr[], int arr_size = 0);
void printArr(int arr[], int size);
int RandomizedPartition(int A[], int p, int r);
void RandomizedQuickSort(int A[], int p, int r);
int RandomizedSelect(int A[], int p, int r, int i);
int maxArr(int A[], int size);