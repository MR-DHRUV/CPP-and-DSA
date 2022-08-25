#include <iostream>
using namespace std;

class Array
{

public:
    int *A;
    int size;
    int length;
    // default constuctor with default argument siz = 10
    Array(int siz = 10) : size(siz)
    {
        A = new int[size];
        length = 0;
    }
    ~Array()
    {
        delete[] A;
    }

    // Input and output functions
    void Display()
    {
        cout << "The array is : ";

        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        };
        cout << endl;
    }

    void SetArray(int n = -1)
    {

        // no arg has been given so take input for all blocks
        if (n == -1)
        {
            for (int i = 0; i < size; i++)
            {
                int input;
                cout << "Enter element " << (i) << " : ";
                cin >> input;
                A[i] = input;
            }

            length = size;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                int input;
                cout << "Enter element " << (i) << " : ";
                cin >> input;
                A[i] = input;
            }

            length = n;
        }
    }

    Array isSum(int sum);
    Array isSumHash(int sum);
    Array isSumSorted(int sum);
    int Max();
};

int Array ::Max()
{
    int max = 0;

    for (int i = 0; i < length; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }

    return max;
    // O(n) always
};

Array Array ::isSum(int sum)
{

    Array returnArr(length);

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (A[i] + A[j] == sum)
            {
                returnArr.A[returnArr.length++] = A[i];
                returnArr.A[returnArr.length++] = A[j];
                cout << A[i] << " and " << A[j] << endl;
            }
        }
    }

    return returnArr;
    // time complexity : O(n^2)
    // space complexity : kam haii
}

// isSum by hash table
Array Array ::isSumHash(int sum)
{
    // this technique is called hash table
    int max = Max();
    cout << "Max : " << max << endl;

    Array returnArr(length);
    Array missing(max);

    for (int l = 0; l < max; l++)
    {
        missing.A[l] = 0;
    }

    missing.length = max;

    for (int i = 0; i < length; i++)
    {
        int element = A[i];
        missing.A[element - 1] = 1;
    }

    for (int j = 0; j < max; j++)
    {
        if (missing.A[sum - A[j]] != 0)
        {

            returnArr.A[returnArr.length++] = sum - A[j];
            returnArr.A[returnArr.length++] = A[j];
            // cout<<returnArr.A[returnArr.length]<<endl;
        }
    }
    // time complexity : O(n) , n is no of elments in an array
    /// space complexity : more

    return returnArr;
};

Array Array ::isSumSorted(int sum)
{

    Array returnArr(length);

    // start
    int i = 0;

    // end
    int j = length-1;

    while (i != j)
    {
        if (A[i] + A[j] > sum)
        {
            j--;
        }
        else if (A[i] + A[j] < sum)
        {
            i++;
        }
        else{
            returnArr.A[returnArr.length++] = A[i]; 
            returnArr.A[returnArr.length++] = A[j]; 
            i++;
            j--;
        }
    }

    return returnArr;
    // time complxity : O(n);
};

int main()
{
    Array arr(10);
    arr.SetArray(8);

    // cout << "duplicate Element : " << arr.isduplicateSorted();

    Array arrResult = arr.isSumHash(10);
    arrResult.Display();

    return 0;
}