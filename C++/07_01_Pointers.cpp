#include <iostream>
using namespace std;

void update(int **p)
{
    // no change
    // p = p+1;

    // updates address stored in *p
    *p = *p + 1;
    // yeh a ab point ni krega uske agle block ko krega

    // updates real value at **p
    // **p = **p+1;
}

int main()
{
    int a = 3;
    int *ptr = &a;
    int **ptrToPtr = &ptr;

    // & is called address of  operator
    cout << **ptrToPtr << endl; // * is called derefrencing operator
    cout << *ptr << endl;
    // cout<<a<<endl;
    cout << ptr << endl;
    cout << *ptrToPtr << endl;
    cout << ptrToPtr << endl;

    cout << endl;
    cout << endl;

    cout << "after";
    cout << endl;

    update(ptrToPtr);

    cout << **ptrToPtr << endl; // * is called derefrencing operator
    cout << *ptr << endl;
    cout << ptr << endl;
    cout << *ptrToPtr << endl;
    cout << ptrToPtr << endl;

    // null pointer
    float a2 = 12.40;

    // segmentation fault
    // *p = a;
    // cout<<*p;

    char c = 'c';
    c++;
    cout << c << endl;




    //important 
    int first = 100;

    int *p = &first;
    int **q = &p;

    int second = ++(**q); // both 101

    int *r = *q;
    ++(*r);

    //*q will give value at p that is address of first
    // so r will be &first and *r will be value at first

    cout << first << " " << second << endl;
    

    return 0;
}