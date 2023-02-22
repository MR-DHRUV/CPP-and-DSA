#include <bits/stdc++.h>
using namespace std;

// usefull for sorting very large sized list
// based on insertion sort

// we require very less shifing when no of elements to be sorted are very less in a list
// adaptive
// inplace

/*
	9 5 16 8 13 6 12 10 4 2 3

	gap = no of elements/2
		= 11/2 = 5

	we'll sort the elements at the gap of 5, then divide that gap and so on...

	element at gap 5 = 6
	element at 0 = 9
	swap(0,5)

	6 5 16 8 13 9 12 10 4 2 3

	i++;
	i = 1;
	element at gap 5 = 12
	element at 1 = 5
	no swap

	6 5 16 8 13 9 12 10 4 2 3
	6 5 10 4 13 9 12 16 8 2 3
	6 5 10 4 2 9 12 16 8 13 3

	6 5 10 4 2 3 12 16 8 13 9  but 6 is also at a gap of 5, so we have to compare with 3 elements
	3 5 10 4 2 6 12 16 8 13 9

	1 gap iteration completed
	gap = gap/2
		   = 2

	3 5 10 4 2 6 12 16 8 13 9
	3 4 10 5 2 6 12 16 8 13 9

	3 4 2 5 10 6 12 16 8 13 9
	// 2 will be compared with 3 as it is also at a gap of 2

	2 4 3 5 10 6 12 16 8 13 9

	2 4 3 5 10 6 8 16 12 13 9 // 8 < 10  second swap
	2 4 3 5 8 6 10 16 12 13 9

	2 4 3 5 8 6 10 13 12 16 9 // 6 < 13 no second swap

	2 4 3 5 8 6 10 13 9 16 12
	2 4 3 5 8 6 9 13 10 16 12 // second swap

	// all the elements at gap of 2 are sorted

	2 gap iteration completed
	gap = gap/2
		= 1

	2 4 3 5 8 6 9 13 10 16 12
	2 3 4 5 8 6 9 13 10 16 12
	2 3 4 5 8 6 9 10 13 16 12
	2 3 4 5 8 6 9 10 13 12 16
	2 3 4 5 8 6 9 10 12 13 16 // second swap for 12

	// work done in each pass is almost O(N) as we are swapping only
	// no of gap passes = 3 = log2N
	// time complexity : O(NlogN)

	// some times gaps are taken as prime numbers like this
	n = 11
	gap => 7 5 3 1
	// time complexity : O(N^3/2)

	depends upon gap
	// time complexity : O(N^5/3)
*/

int shellSort(int arr[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int temp = arr[i];

			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
			{
				arr[j] = arr[j - gap];
			}

			arr[j] = temp;
		}
	}

	return 0;
}

int main()
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