#include <iostream>
using namespace std;

int BinInfinity(int arr[], int target)
{
    int loc1 = 0;
    int loc2 = 1;

    // location calculator

    int i = 0;

    while (target >= arr[loc2])
    {
        if(arr[loc1] == target){
            return loc1;
        }
        if(arr[loc2] == target){
            return loc2;
        }
        if (arr[loc2] < target)
        {
            i++;
            loc1 = loc2;
            loc2  += (i+1) *2 ;
        }
    }

    int start = loc1;
    int end = loc2;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        else if (arr[mid] > target)
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

int main()
{

    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 23, 45, 70, 89};

    cout << BinInfinity(arr, 2)<<endl;
    cout << BinInfinity(arr, 3)<<endl;
    cout << BinInfinity(arr, 7)<<endl;
    cout << BinInfinity(arr, 8)<<endl;
    cout << BinInfinity(arr, 20)<<endl;
    cout << BinInfinity(arr, 70)<<endl;
    cout << BinInfinity(arr, 89)<<endl;
    cout << BinInfinity(arr, 890)<<endl;

    return 0;
}