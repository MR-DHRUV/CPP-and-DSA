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

// adding a elemnt in the last, i.e jo block khaali haii sabse kam index pr uspe aadd krdo
void Append(struct Array *arr, int element)
{
    if (arr->length < arr->size)
    {

        arr->A[arr->length] = element;
        arr->length++;
    }
}

// inserting element at given index
void Insert(struct Array *arr, int index, int elemnt)
{

    if (index >= 0 && index <= arr->length && index < arr->size)
    {

        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }

        arr->A[index] = elemnt;

        arr->length++;
    }
    else{
        cout<<"Invalid index"<<endl;
    }
    // best time O(1) : jab last me add kiya
    // worst time O(n) : jab start me add kiya
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

    Append(ptr, 6);
    Display(arr);

    // index starts from 0;
    Insert(ptr, 6, 100);

    Display(arr);

    return 0;
}
