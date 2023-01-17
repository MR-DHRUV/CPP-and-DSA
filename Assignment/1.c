#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int *A;
    int size;
    int length;
};
void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Insert(struct Array *arr, int index, int x)
{

    if (arr->length >= arr->size)
    {
        printf("Array is full\n");
        return;
    }

    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }

        arr->A[index] = x;
        arr->length++;
    }
}
int Delete(struct Array *arr, int index)
{
    if (arr->length <= 0)
    {
        printf("Array is empty\n");
        return -1;
    }

    int x = 0;
    int i;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
        return x;
    }
    return 0;
}

int LinearSearch(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            return i;
        }
    }
    return -1;
}

void selectionSort(struct Array *arr)
{
    for (int i = 0; i < arr->length - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < arr->length; j++)
        {
            if (arr->A[j] < arr->A[minIndex])
            {
                minIndex = j;
            }
        }

        swap(&arr->A[i], &arr->A[minIndex]);
    }
}
int main()
{
    struct Array arr1;
    int ch;
    int x, index;
    int inp, idx, ele;
    printf("Enter Size of Array : ");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    arr1.length = 0;
    do
    {
        printf("0. Sort\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("6.Exit\n");
        printf("enter you choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            if (arr1.length > 1)
            {
                selectionSort(&arr1);
            }
            Display(arr1);
            break;
        case 1:
            printf("Enter\n1 for begining\n2 for end\n3 for index\n");
            scanf("%d", &inp);
            if (inp == 1)
            {
                idx = 0;
            }
            else if (inp == 2)
            {
                idx = arr1.length;
            }
            else
            {
                printf("Enter the index  : ");
                scanf("%d", &idx);
            }
            printf("Enter the element : ");
            scanf("%d", &ele);
            Insert(&arr1, idx, ele);
            break;
        case 2:
            printf("Enter\n1 for begining\n2 for end\n3 for index\n");
            scanf("%d", &inp);
            if (inp == 1)
            {
                idx = 0;
            }
            else if (inp == 2)
            {
                idx = arr1.length;
            }
            else
            {
                printf("Enter the index  : ");
                scanf("%d", &idx);
            }
            x = Delete(&arr1, idx);
            printf("Deleted Element is %d\n", x);
            break;
        case 3:
            printf("Enter element to search : ");
            scanf("%d", &x);
            index = LinearSearch(&arr1, x);
            printf("Element index %d\n", index);
            break;
        case 4:
            Display(arr1);
        }
    } while (ch < 6);
    return 0;
}