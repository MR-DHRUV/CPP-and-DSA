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
    cout<<endl;
}


// adding a elemnt in the last, i.e jo block khaali haii sabse kam index pr uspe aadd krdo
void Append(struct Array *arr, int element)
{
    if(arr->length < arr->size){

        arr->A[arr->length]  = element;
        arr->length ++ ;
    }
}

int main()
{
    // same driver code
    struct Array arr;
    cout << "Enter size of an array : ";
    cin >> arr.size;

    arr.A = new int[arr.size];
    arr.length = 0; // as no elemnt is there curretly

    int n;
    cout << "Enter the no of elements you want to enter : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << "th element : ";
        cin >> arr.A[i];
    }

    arr.length = n;

    Display(arr);

    struct Array *ptr = &arr;

    Append(ptr,6);
    Display(arr);

    return 0;
}