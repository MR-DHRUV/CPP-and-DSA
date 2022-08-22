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

    Array DuplicateSorted();
    Array Duplicate();

};



Array Array ::DuplicateSorted()
{
    // this works for N  duplicate element
    Array duplicate(length);

    int val = A[0];

    for (int i = 0; i < length; i++)
    {
        if (A[i] == A[i+1])
        {
            duplicate.A[duplicate.length++] = A[i];
        }
    }

    // time complexity : O(n) , n is no of elments in an array

    return duplicate;
}




//method 2 
// univarsal method , works for 1 , more 1 one duplicate , sorted , unsorted
Array Array ::Duplicate()
{
    // this technique is called hash table 
    
    Array returnArr(length);
    Array duplicate(length);

    // initialised hash table
    for (int l = 0; l < length; l++)
    {
        duplicate.A[l] = 0; 
    }

    duplicate.length = length;
    
    for (int i = 0; i < length; i++)
    {
        duplicate.A[A[i] - 1] ++;
    }

    duplicate.Display();

    for (int j = 0; j < length; j++)
    {
        if(duplicate.A[j] > 1){
            returnArr.A[returnArr.length++] = (j+1);
        }
    }
    

    // time complexity : O(n) , n is no of elments in an array

    return returnArr;
}





int main()
{
    Array arr(10);
    arr.SetArray(8);

    // cout << "duplicate Element : " << arr.isduplicateSorted();

    Array arrResult = arr.Duplicate();
    arrResult.Display();

    return 0;
}