#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(&arr[i], &arr[minIndex]);
        printArr(arr, n);
    }
}

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwaped = false;

        for (int j = 0; j < n - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                isSwaped = true;
            }
        }

        printArr(arr, n);

        if (!isSwaped)
        {
            break;
        }
    }
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

        // j+1 islie hua kyuki else wale case me ek aur baar peeeche chala jayga
        arr[j + 1] = temp;

        printArr(arr, n);
    }
}

int shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }

        printArr(arr, n);
    }
    return 0;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];

    int cnt = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    // now we have no of elements less than or equal to pivot

    // placing pivot at its right position
    int pivotIndex = start + cnt;
    swap(&arr[pivotIndex], &arr[start]);

    // left and right wala paart sahi krna haii taaki usne greater aur lesser elements ho

    int i = start;
    int j = end;

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

void quickSort(int arr[], int start, int end)
{
    // if equal then arr of size 1 and when start > end then size 0 , already sorted case
    if (start >= end)
    {
        return;
    }

    // partition krenge aur 1st element ko uski sahi jagah par lagayenge
    int p = partition(arr, start, end);

    // sorting left part
    quickSort(arr, start, p - 1);
    printArr(arr, end);

    // sorting right part
    quickSort(arr, p + 1, end);
    printArr(arr, end);

    return;
}

void heapify(int arr[], int n, int i)
{
    int left = (2 * i) + 1;

    while (left < n)
    {
        int right = left + 1;

        // checking for right
        if (right < n && arr[right] > arr[left])
        {
            if (arr[i] < arr[right])
            {
                swap(&arr[i], &arr[right]);
                i = right;
                left = (2 * i) + 1;
            }
            else
            {
                break;
            }
        }
        else if (arr[i] < arr[left])
        {
            swap(&arr[i], &arr[left]);
            i = left;
            left = (2 * i) + 1;
        }
        else
        {
            break;
        }
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void del(int arr[], int n)
{
    if (n < 1)
    {
        return;
    }

    swap(&arr[0], &arr[n]);
    heapify(arr, n, 0);
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);

    for (int i = n - 1; i >= 0; i--)
    {
        del(arr, i);
        printArr(arr, n);
    }
}

void merge(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;

    // length haii index nahi isiliye +1 hua
    int len1 = mid - start + 1;

    // end has already 1 added
    int len2 = end - mid;

    int first[len1];
    int second[len2];

    // copying half arrays (total complexity : O(N) )
    int k = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k];
        k++;
    }

    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k];
        k++;
    }

    // merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;

    // index of main array
    k = start;

    // Total complexity : O(N)
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[k++] = first[index1++];
        }
        else
        {
            arr[k++] = second[index2++];
        }
    }

    // agar koi part lamba hua
    while (index1 < len1)
    {
        arr[k++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[k++] = second[index2++];
    }
}

void mergeSort(int *arr, int start, int end)
{
    // base case

    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    // sorting left part;
    mergeSort(arr, start, mid);

    // sorting right part;
    mergeSort(arr, mid + 1, end);

    merge(arr, start, end);
    printArr(arr,end);
}

int main(int argc, char const *argv[])
{
    bool menu = true;

    int n;
    printf("Enter the no of elements in the array : ");
    scanf("%d", &n);

    int arr[n];
    int temp[n];

    printf("Enter the elements of the array \n");
    int j = n;
    int i = 0;
    while (j--)
    {
        scanf("%d", &arr[i++]);
        temp[i - 1] = arr[i - 1];
    }

    // menu
    while (menu)
    {
        printf("Press\n1 for bubble sort \n2 for selection sort\n3 for insertion sort\n4 for shell sort\n5 for quick sort\n6 for heap sort\n7 for merge sort\n8 for exit\n");
        int i;
        scanf("%d", &i);

        if (i == 1)
        {
            bubbleSort(arr, n);
        }
        else if (i == 2)
        {
            selectionSort(arr, n);
        }
        else if (i == 3)
        {
            insertionSort(arr, n);
        }
        else if (i == 4)
        {
            shellSort(arr, n);
        }
        else if (i == 5)
        {
            quickSort(arr, 0, n);
        }
        else if (i == 6)
        {
            heapSort(arr, n);
        }
        else if (i == 7)
        {
            mergeSort(arr,0,n);
        }
        else if (i == 8)
        {
            menu = false;
            break;
        }
        else
        {
            printf("Invalid Input\n");
        }

        // reset
        for (int i = 0; i < n; i++)
        {
            arr[i] = temp[i];
        }
    }

    return 0;
}
