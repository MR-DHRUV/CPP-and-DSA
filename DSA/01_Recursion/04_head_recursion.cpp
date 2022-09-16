#include <iostream>
using namespace std;

// head recursion
int func(int n)
{
    if (n > 0)
    {
        // sabse pahle reccursive call ho
        func(n - 1);
        cout << n << endl;
        // printing is done at returning time
    }

    return 0;
}

// consersion to loop is not as easy as it was to convert a tail recursive function to loop
// some modifications will be required

// conversion to loop
int funcLoop(int n)
{
    int i = 1;

    while (i <= n)
    {
        cout << i << endl;
        i++;
    }

    return 0;
}

int main()
{
    func(3);
    funcLoop(3);

    return 0;
}

// time complexity of both is O(n) as same no calls are being made

// space comlexity

// recursion stack me naye "n" banayga for each iteration
// space complexity = O(n)

// loop ek hi n ko decrese kr rha haii, koi nayi copy ni ban rahi nayi iteration ke liye
// so space complexity for loop = O(1) = constant
