#include <iostream>
using namespace std;

class __declspec(dllexport) Array
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

    int isMissingSorted();
    Array isMissingSortedN();
    Array isMissing();
    int Max();
};

// finding missiong elements in a sorted array
// 1 2 4 5 me 3 missing haii aise

// it works on the fact that in in a sorted array like 1 2 3 4 5 6 , the diffrence of values corresponding to their index will be always constant;

// 1 2 3 4 5 6
// 0 1 2 3 4 5
// - - - - - -
// 1 1 1 1 1 1
int Array ::isMissingSorted()
{
    // this only works for 1 missing element
    int val = A[0];

    for (int i = 0; i < length; i++)
    {
        if (A[i] - i != val)
        {
            return (i + val);
        }
    }

    return 0;
}

Array Array ::isMissingSortedN()
{
    // this works for N  missing element
    Array missing(length);

    int val = A[0];

    for (int i = 0; i < length; i++)
    {
        if (A[i] - i != val)
        {
            while (val < A[i] - i)
            {
                missing.A[missing.length] = i + val;
                missing.length++;
                val++;
            }
        }
    }

    // time complexity : O(n) , n is no of elments in an array

    return missing;
}

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




//method 2 
// univarsal method , works for 1 , more 1 one missing , sorted , unsorted
Array Array ::isMissing()
{
    // this technique is called hash table 
    int max = Max();
    cout<<"Max : "<<max<<endl;

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
        missing.A[element-1] = 1;
    }

    for (int j = 0; j < max; j++)
    {
        if(missing.A[j] == 0){
            returnArr.A[returnArr.length] = (j+1);
            cout<<returnArr.A[returnArr.length]<<endl; 
            returnArr.length++;
        }
    }
    

    // time complexity : O(n) , n is no of elments in an array

    return returnArr;
}





int main()
{
    Array arr(10);
    arr.SetArray(5);

    // cout << "Missing Element : " << arr.isMissingSorted();

    Array arrResult = arr.isMissing();
    arrResult.Display();

    return 0;
}