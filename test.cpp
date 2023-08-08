/******************************************************************************

							  Online C++ Debugger.
			   Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <iostream>

using namespace std;

void duplicate()
{
	int a[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
	int length = sizeof(a) / sizeof(int);
	int maxEle = -1;

	for (int i = 0; i < length; i++)
	{
		cout << a[i] << " ";
		maxEle = max(maxEle, a[i]); // calculate max element of the array
	}
	cout << endl;

	int *H = new int[maxEle + 1]{};
	for (int i = 0; i < length; i++)
	{
		if (a[i] >= 0)
		{
			H[a[i]]++;
			cout << H[a[i]] << " ";
		}
	}
	cout << endl;

	for (int i = 0; i <= maxEle; i++)
	{
		cout << H[i] << " times: " << i << endl;
	}
}

int main()
{
	duplicate();

	return 0;
}
