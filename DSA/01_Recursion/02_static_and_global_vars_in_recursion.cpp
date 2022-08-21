#include <iostream>
using namespace std;

int func(int n)
{
    if (n > 0)
    {
        return func(n - 1) + n;
    }

    return 0;
}

int funcStatic(int n)
{
    static int x = 0;
    // result will be same if x is made global insted of static

    if (n > 0)
    {
        x++;
        return funcStatic(n - 1) + x;
    }

    return 0;
}

int main()
{
    int a = 5;
    // cout<<func(a);
    cout << funcStatic(a);

    return 0;
}

// total calls
// 5 4 3 2 1 0 = 6
// n+1
// O(n)

// static and global variables are stored in code section of memory and during runtime only 1 copy of them is made