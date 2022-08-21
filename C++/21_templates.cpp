#include <iostream>
using namespace std;

// templates are used to promote code reusabillity thus DRY is promoted
// dry -> do not repeat yourself
// templates are generic -> can be used for any data type



// so this whole code works only for int 
// in order to make a reusble class for various data types we use templete 

// class vector
// {
//     int size;

// public:
//     int *arr;
//     vector(int m)
//     {
//         size = m;
//         arr = new int[size];
//     };

//     int dotProduct(vector &v)
//     {
//         int d = 0;

//         for (int i = 0; i < size; i++)
//         {
//             d += this->arr[i] * (v.arr[i]);
//         };
//         return d;
//     };
// };


// int main()
// {
//     vector v1(3);
//     v1.arr[0] = 4;
//     v1.arr[1] = 3;
//     v1.arr[2] = 1;

//     vector v2(3);
//     v2.arr[0] = 1;
//     v2.arr[1] = 0;
//     v2.arr[2] = 1;

//     int dot = v1.dotProduct(v2);
//     cout << dot << endl;

//     return 0;
// }

// t is a data type of template that can be defined later while filling it

template <class T>

class vector
{
    int size;

public:
    T *arr;

    vector(int m)
    {
        size = m;
        arr = new T[size];
    };

    T dotProduct(vector &v)
    {
        T d = 0;

        for (int i = 0; i < size; i++)
        {
            d += this->arr[i] * (v.arr[i]);
        };
        return d;
    };
};


int main()
{
    vector <int> v1(3);
    v1.arr[0] = 4;
    v1.arr[1] = 3;
    v1.arr[2] = 1;

    vector <int> v2(3);
    v2.arr[0] = 1;
    v2.arr[1] = 0;
    v2.arr[2] = 1;

    int dot = v1.dotProduct(v2);
    cout << dot << endl;


    vector <float> v3(3);
    v3.arr[0] = 1.4;
    v3.arr[1] = 3.3;
    v3.arr[2] = 0.1;

    vector <float> v4(3);
    v4.arr[0] = 0.1;
    v4.arr[1] = 1.90;
    v4.arr[2] = 4.1;

    float dotF = v3.dotProduct(v4);
    cout << dotF << endl;

    return 0;
}