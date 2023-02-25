#include <stdio.h>
#include <stdlib.h>


typedef struct Queue
{
	int size;
	int *q;
	int front;
	int back;
}Queue;

void init(Queue *qt, int n)
{
	qt->size = n;
	qt->front = 0;
	qt->back = 0;
	qt->q = (int *)malloc(sizeof(int)*n);
}

bool isEmpty(Queue *qt)
{
	if(qt->front == qt->back)
	{
		return true;
	}

	return false;
}

bool isFull(Queue *qt)
{
	if((qt->back+1)%qt->size == qt->front)
	{
		return true;
	}

	return false;
}

void enqueue(Queue *qt, int n)
{
	if(isFull(qt))
	{
		return;
	}

	qt->back = (qt->back+1)%qt->size;
	qt->q[qt->back] = n;
}

void dequeue(Queue *qt)
{
	if(isEmpty(qt))
	{
		return;
	}

	qt->front = (qt->front+1)%qt->size;
}

int atFront(Queue *qt)
{
	if(isEmpty(qt))
	{
		return INT_MAX;
	}

	return qt->q[qt->front+1];
}


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int *arr, int n, int s)
{
	int largest = s;

	int l = (2 * s) + 1;
	int r = (2 * s) + 2;

	if (l < n && arr[l] > arr[largest])
	{
		largest = l;
	}

	if (r < n && arr[r] > arr[largest])
	{
		largest = r;
	}

	if (largest != s)
	{
		swap(&arr[s], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapifyArr(int *arr, int n)
{
	// last leaf -> n/2
	for (int i = (n / 2) - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}
}

void del(int *arr, int n)
{
	swap(&arr[0], &arr[n]);
	heapify(arr, n, 0);
}

void HeapSort(int *arr, int n)
{
	heapifyArr(arr, n);

	for (int i = 0; i < n; i++)
	{
		del(arr, n - i - 1);
	}
}

// quick sort

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

	int i = 0;
	int j = e;

	while (i < pivotIndex && j > pivotIndex)
	{
		while (arr[i] < pivot)
		{
			i++;
		}

		while (arr[j] >= pivot)
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

void QuickSort(int *arr, int s, int e)
{
	if (s >= e)
	{
		return;
	}

	int p = partition(arr, s, e);
	QuickSort(arr, s, p - 1);
	QuickSort(arr, p + 1, e);
}

void merge(int *arr, int s, int e)
{
	int mid = s + (e - s) / 2;

	int len1 = mid - s + 1;
	int len2 = e - mid;

	int arr1[len1];
	int arr2[len2];

	int k = s;

	for (int i = 0; i < len1; i++)
	{
		arr1[i] = arr[k++];
	}
	for (int i = 0; i < len2; i++)
	{
		arr2[i] = arr[k++];
	}

	// merge
	k = s;
	int i = 0, j = 0;

	while (i < len1 && j < len2)
	{
		if (arr1[i] < arr2[j])
		{
			arr[k++] = arr1[i++];
		}
		else
		{
			arr[k++] = arr2[j++];
		}
	}

	while (i < len1)
	{
		arr[k++] = arr1[i++];
	}
	while (j < len2)
	{
		arr[k++] = arr2[j++];
	}
};

void MergeSort(int *arr, int s, int e)
{
	if (s >= e)
	{
		return;
	}

	int mid = s + (e - s) / 2;

	MergeSort(arr, s, mid);
	MergeSort(arr, mid + 1, e);

	merge(arr, s, e);
}

void InsertionSort(int *arr, int n)
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

void ShellSort(int *arr, int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int temp = arr[i];
			int j = i;

			for (; j >= gap && arr[j - gap] > temp; j-=gap)
			{
				arr[j] = arr[j-gap];
			}
			arr[j] = temp; 
		}
	}
}



int main()
{
	int arr[] = {7, 8, 4, 9, 1, 6, 2, 3};
	ShellSort(arr, 8);

	for (int i = 0; i < 8; i++)
	{
		printf("%d ", arr[i]);
	}


	Queue qt;
	init(&qt,5);
	enqueue(&qt,6);
	enqueue(&qt,7);
	enqueue(&qt,8);
	enqueue(&qt,8);
	enqueue(&qt,8);
	enqueue(&qt,8);
	enqueue(&qt,8);
	enqueue(&qt,8);
	printf("%d\n",atFront(&qt));
	dequeue(&qt);
	printf("%d\n",atFront(&qt));

	return 0;
}
