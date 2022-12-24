#include <stdio.h>
#include <stdlib.h>

int binSRec(int arr[], int target, int start, int end)
{

    if (start == end && arr[start] != target)
    {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return binSRec(arr, target, start, mid - 1);
    }
    else
    {
        return binSRec(arr, target, mid + 1, end);
    }
}

// quick sort
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{

    int n;
    printf("Enter the size of array : ");
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);

    int i = 0;
    int j = n;
    printf("Enter the elements of array\n");

    while (j--)
    {
        scanf("%d", &arr[i++]);
    }

    quickSort(arr, 0, n - 1);

    while (true)
    {
        int t;
        printf("Enter -1 to exit\n");
        printf("Enter the element you want to find : ");
        scanf("%d", &t);

        if (t == -1)
            return 0;

        int isPresent = binSRec(arr, t, 0, 8);

        if (isPresent == -1)
        {
            printf("The given element is not present \n");
        }
        else
        {
            printf("The given element is present in given array at index %d \n", isPresent);
        }
    }

    return 0;
}