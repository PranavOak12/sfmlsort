#include "sortingalgorithms.h"
#include "otherfunctionss.h"
#include <bits/stdc++.h>
using namespace std;
void sswap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubblesort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int flag = 1;
        for (int j = 0; j < size - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                sswap(array[j], array[j + 1]);
                printchange(array, size);
                flag = 0;
            }
        }
        if (flag)
        {
            break;
        }
    }
}

void selectionsort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minindex])
            {
                minindex = j;
            }
        }
        sswap(array[minindex], array[i]);
        printchange(array, size);
    }
}

void insertionsort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (array[j] < array[j - 1])
            {
                sswap(array[j], array[j - 1]);
                printchange(array, size);
            }
        }
    }
    return;
}

void merge2(int array2[], int start, int mid, int end, int size)
{
    int i = start;
    int j = mid + 1;
    vector<int> temp;
    while ((i <= mid) and (j <= end))
    {
        if (array2[i] < array2[j])
        {
            temp.push_back(array2[i]);
            i++;
        }
        else
        {
            temp.push_back(array2[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(array2[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(array2[j]);
        j++;
    }
    for (int x = start; x <= end; x++)
    {
        array2[x] = 0;
    }
    printchange(array2, size);
    for (int y = 0; y < (end - start + 1); y++)
    {
        array2[start + y] = temp[y];
        printchange(array2, size);
    }
}

void mergesort(int array1[], int start, int end, int size)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergesort(array1, start, mid, size);
        mergesort(array1, mid + 1, end, size);
        merge2(array1, start, mid, end, size);
    }
    else
    {
        return;
    }
}

int pindexfuncbabbar(int array[], int start, int end, int size)
{
    // introduced count function
    return 0;
}

int pindexfuncstriv(int array[], int start, int end, int size)
{
    int pivot = array[start];
    int i = start;
    int j = end;
    while (i < j)
    {
        while ((i <= end - 1) and (array[i] <= pivot))
        {
            i++;
        }
        while ((j >= start + 1) and (array[j] >= pivot))
        {
            j--;
        }
        if (i < j)
        {
            sswap(array[i], array[j]);
            printchange(array, size);
        }
    }

    sswap(array[j], array[start]);
    if (j != start)
    {
        printchange(array, size);
    }
    return j;
}

void quicksort(int array[], int start, int end, int size)
{
    if (start < end)
    {
        int pivotindex = pindexfuncstriv(array, start, end, size);
        quicksort(array, start, pivotindex, size);
        quicksort(array, pivotindex + 1, end, size);
    }
}
