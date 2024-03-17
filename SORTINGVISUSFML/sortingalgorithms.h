#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <iostream>
#include <vector>

void sswap(int &a, int &b);
void bubblesort(int array[], int size);
void selectionsort(int array[], int size);
void insertionsort(int array[], int size);
void merge2(int array2[], int start, int mid, int end, int size);
void mergesort(int array1[], int start, int end, int size);
int pindexfuncbabbar(int array[], int start, int end, int size);
int pindexfuncstriv(int array[], int start, int end, int size);
void quicksort(int array[], int start, int end, int size);

#endif // SORTING_ALGORITHMS_H
