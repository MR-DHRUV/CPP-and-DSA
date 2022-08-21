#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    cout << "The array is" << endl;

    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    };
    cout << endl;
}



int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }

    else
    {
        return -1;
    }
}

void Set(struct Array *arr, int index, int element)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = element;
    }
}

int Max(struct Array arr)
{
    int max = 0;

    for (int i = 0; i < arr.length; i++)
    {
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    }

    return max;
    // O(n) always
}

int Sum(struct Array arr)
{
    int sum = 0;

    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }

    return sum;
    // O(n) always
}

double Avg(struct Array arr)
{
    int sum = Sum(arr);

    return ((double)sum / (arr.length )) ;
    // O(n) always
}






int main()
{
    // same driver code
    struct Array arr;
    arr.size = 11;
    arr.A = new int[arr.size];

    for (int i = 0; i < arr.size; i++)
    {
        arr.A[i] = i + 1;
    }

    arr.length = 11;
    Display(arr);
    cout<<endl;

    Display(arr);

    struct Array *ptr = &arr;

    
    Set(ptr, 5 , 100);

    cout<<Get(arr, 5)<<endl;
    Display(arr);
    cout<<Max(arr)<<endl;
    cout<<Sum(arr)<<endl;
    cout<<Avg(arr)<<endl;


    return 0;
}
