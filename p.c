#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = temp;
    }
}

void merge(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *arr1 = (int *)malloc(sizeof(int) * len1);
    int *arr2 = (int *)malloc(sizeof(int) * len2);

    int k = start;

    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[k++];
    }

    for (int i = 0; i < len1; i++)
    {
        arr2[i] = arr[k++];
    }

    int i1 = 0;
    int i2 = 0;
    k = start;

    while (i1 < len1 && i2 < len2)
    {
        if (arr1[i1] < arr2[i2])
        {
            arr[k++] = arr1[i1++];
        }
        else
        {
            arr[k++] = arr2[i2++];
        }
    }

    while (i1 < len1)
    {
        arr[k++] = arr1[i1++];
    }

    while (i2 < len2)
    {
        arr[k++] = arr2[i2++];
    }
}

void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

int partition(int *arr, int s, int e)
{
    int pivot = arr[s];

    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    int pivotIndex = s + cnt;
    swap(&arr[s], &arr[pivotIndex]);

    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(&arr[i++], &arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int p = partition(arr, s, e);

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

void shellSort(int *arr, int n)
{
    for (int gap = n/2; gap > 0; gap/=2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j-gap] > temp ; j-=gap )
            {
                arr[j] = arr[j-gap];
            }

            arr[j] = temp;
            
        }
        
    }
    
}


int main(int argc, char const *argv[])
{

    int arr[] = {1, 8, 9, 6, 4, 8, 65, 4, 1, 7, 8};

    // mergeSort(arr,0,11);
    shellSort(arr, 11);

    for (int i = 0; i < 11; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}