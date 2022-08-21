#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
    // Function objects/ functer : A function wrapped in a class, so that it is available like an object
    // why do we need function objects

    int arr[] = {8, 2, 3, 4, 6, 5, 7, 1};

    //
    sort(arr, arr + 8);

    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    // greater<int>() is a function object
    sort(arr, arr + 8, greater<int>());

    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}