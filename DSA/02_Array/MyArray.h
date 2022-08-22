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

    // Operation functions
    void Append(int element);
    void Insert(int index, int elemnt);
    void Delete(int index);
    int linearSearch(int key);
    int binarySearch(int key);
    int Get(int index);
    int Sum();
    int Max();
    int Min();
    Array MinMax();
    double Avg();
    void Reverse();
    void Lshift();
    void Rshift();
    void Rotate(int n);
    void SortedInsert(int element);
    bool isSorted();
    void Merge(Array arr1, Array arr2);
    void SortedUnion(Array arr1, Array arr2);
    void Intersection(Array arr1, Array arr2);
    void Diffrence(Array arr1, Array arr2);
    void Union(Array arr1, Array arr2);
    Array isMissing();
    Array Duplicate();

};

// adding a elemnt in the last, i.e jo block khaali haii sabse kam index pr uspe aadd krdo
void Array ::Append(int element)
{
    if (length < size)
    {
        A[length] = element;
        length++;
    }
};

// inserting element at given index
void Array ::Insert(int index, int elemnt)
{

    if (index >= 0 && index <= length && index < size)
    {

        for (int i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }

        A[index] = elemnt;

        length++;
    }
    else
    {
        cout << "Invalid index" << endl;
    }
    // best time O(1) : jab last me add kiya
    // worst time O(n) : jab start me add kiya
};

void Array ::Delete(int index)
{
    if (index >= 0 && index < length)
    {

        for (int i = index; i < length; i++)
        {
            A[i] = A[i + 1];
        }

        length--;
    }
    else
    {
        cout << "Invalid index" << endl;
    }

    // best time : O(1)
    // worst time : O(n)
};

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
};

int Array ::linearSearch(int key)
{
    int index = 0;

    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
        {

            // int temp = A[i];
            // A[i] = A[i - 1];
            // A[i - 1] = temp;

            // better method
            swap(&A[i], &A[0]);

            return i;
        }
    }

    // when an element is search, its a high prbability that it will be searched again, so it is moved 1 index closer every time is is searched and ithis process is called transposition

    // another method is to brought the element searched to index 0

    return -1;
};

int Array ::binarySearch(int key)
{
    // to perform binary search the key condition is that the array must be sorted in assending order

    // to perform binary search we need 3 variables
    // low = index of smallest element
    // high = index of largest element
    // middle = low+high/2

    // concepts : low = mid + 1
    // concepts : high = mid - 1
    // concepts : divide list by 2 every time in this method

    // init
    int low = 0;
    int high = length;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (A[mid] == key)
        {
            return mid;
        }

        else if (A[mid] > key)
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return -1;
    // Complexity of binary search  for both methods are same;
    //  best = O(1)
    //  worst = O(log2N) log N base 2
};

int Array ::Get(int index)
{
    if (index >= 0 && index < length)
    {
        return A[index];
    }

    else
    {
        return -1;
    }
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

int Array ::Min()
{
    int min = 0;

    for (int i = 0; i < length; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }

    return min;
    // O(n) always
};

Array Array ::MinMax()
{
    Array returnArray(2);
    returnArray.length  = 2;
    
    //min
    returnArray.A[0] = A[0];
    
    //max
    returnArray.A[1] = 0;

    for (int i = 0; i < length; i++)
    {
        if (A[i] < returnArray.A[0])
        {
            returnArray.A[0] = A[i];
        }

        if (A[i] > returnArray.A[1])
        {
            returnArray.A[1] = A[i];
        };
    }

    return returnArray;
    // O(n) always
};


int Array ::Sum()
{
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += A[i];
    }

    return sum;
    // O(n) always
};

double Array ::Avg()
{
    int sum = Sum();

    return ((double)sum / (length));
    // O(n) always
};

void Array ::Reverse()
{
    // swaping last with fist
    int j = length - 1;

    for (int i = 0; i < length / 2; i++)
    {
        swap(&A[i], &A[j]);
        j--;
    }
};

// left shift : sabko 1 - 1 krke leftme kardo aur jo right me 1 space bacche waha 0 lagado

void Array ::Lshift()
{
    int i = 0;

    for (i; i < length; i++)
    {
        A[i] = A[i + 1];
    }

    A[length - 1] = 0;
};

void Array ::Rshift()
{
    int i = length;

    for (i; i > 0; i--)
    {
        A[i] = A[i - 1];
    }

    A[0] = 0;
};

// Rotation : 1st element ko last me lagado;
void Array ::Rotate(int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = A[0];
        Lshift();
        A[length - 1] = temp;
    }
};

// inserting element in sorted array such that it reamins sorted
void Array ::SortedInsert(int element)
{
    int len = length;

    if (len < size)
    {
        // ulta start hoga loop
        // last se check karega small haii ya bada
        // if element to be insterted small then element at  i-1 ko i pe copu krdega as i empty haii  and loopp will continue
        // if element to be insterted larger then usse i pr laga dega aur break;
        for (int i = len; i > 0; i--)
        {
            if (element < A[i - 1])
            {
                A[i] = A[i - 1];
            }

            else
            {
                A[i] = element;
                break;
            }
        }

        length++;
    }
    else
    {
        cout << "Array is completely filled" << endl;
    }
};

bool Array ::isSorted()
{
    // last elemnt ke lie nahi chalana so length -1
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            return false;
        }
    }

    return true;
};

// if arrays are sorted then sorted array will be output else unsorted for unsorted array
void Array::Merge(Array arr1, Array arr2)
{
    int i, j, k;
    i = j = k = 0;

    // Array *arr3;
    // arr3 = new Array[sizeof(Array)];
    // size = 10;
    // size = 10;

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
        {
            A[k++] = arr1.A[i++];
        }
        else
        {
            A[k++] = arr2.A[j++];
        }
    }

    for (; i < arr1.length; i++)
    {
        A[k++] = arr1.A[i];
    }
    for (; j < arr2.length; j++)
    {
        A[k++] = arr2.A[j];
    }
    length = arr1.length + arr2.length;
};

void Array ::Union(Array arr1, Array arr2)
{

    int i = 0;

    for (; i < arr1.length; i++)
    {
        A[i] = arr1.A[i];
    }

    int duplicacy = 0;
    // 2nd array cant be copied blindly as we cant add duplicate elements

    for (int j = 0; j < arr2.length; j++)
    {
        bool same = false;

        for (int k = 0; k < arr1.length; k++)
        {

            if (A[k] == arr2.A[j])
            {
                same = true;
                duplicacy++;
            }
        }

        if (same == false)
        {
            A[i] = arr2.A[j];
            i++;
        }
    }

    // so that no trash elment is printed
    length = arr1.length + arr2.length - duplicacy;

    // O(n^2)
};

void Array ::SortedUnion(Array arr1, Array arr2)
{

    if (arr1.isSorted() == true && arr2.isSorted() == true)
    {

        int i, j, k;
        i = j = k = 0;

        // struct Array *arr3;
        // arr3 = new struct Array[sizeof(struct Array)];
        // size = 10;

        int duplicacy = 0;

        while (i < arr1.length && j < arr2.length)
        {
            if (arr1.A[i] == arr2.A[j])
            {
                A[k++] = arr1.A[i++];
                j++;
                duplicacy++;
            }

            else if (arr1.A[i] < arr2.A[j])
            {
                A[k++] = arr1.A[i++];
            }
            else
            {
                A[k++] = arr2.A[j++];
            }
        }

        for (; i < arr1.length; i++)
        {
            A[k++] = arr1.A[i];
        }
        for (; j < arr2.length; j++)
        {
            A[k++] = arr2.A[j];
        }

        // so that no trash elment is printed
        length = arr1.length + arr2.length - duplicacy;
    }

    else
    {
        cout << "Given arrays are unsorted" << endl;
        ;
    }

    // O(n)
};

// if  unsorted array is given the unsorted array is result
// if  sorted array is given the sorted array is result
void Array ::Intersection(Array arr1, Array arr2)
{

    // struct Array *arr3;
    // arr3 = new struct Array[sizeof(struct Array)];
    // arr3->size = 10;

    for (int i = 0; i < arr1.length; i++)
    {
        for (int j = 0; j < arr2.length; j++)
        {
            if (arr2.A[j] == arr1.A[i])
            {
                A[length] = arr1.A[i];
                length++;
            }
        }
    }

    // O(n^2)
};

// arr1 - arr2
void Array ::Diffrence(Array arr1, Array arr2)
{

    // struct Array *arr3;
    // arr3 = new struct Array[sizeof(struct Array)];
    // arr3->size = 10;

    for (int i = 0; i < arr1.length; i++)
    {
        bool isPresent = false;

        for (int j = 0; j < arr2.length; j++)
        {
            if (arr2.A[j] == arr1.A[i])
            {
                isPresent = true;
            }
        }

        if (isPresent == false)
        {
            A[length] = arr1.A[i];
            length++;
        }
    }

    // O(n^2)
};


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
};


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
