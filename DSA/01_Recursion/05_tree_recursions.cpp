#include <iostream>
using namespace std;

// when a function calls itself just once then it is called Linear recursion.

// when a function calls itself more than once then it is called tree recursion.

void treeRec(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        treeRec(n - 1);
        treeRec(n - 1);
    }
}
// output
// 3
// 2
// 1
// 1
// 2
// 1
// 1


int main()
{
    treeRec(3);
    return 0;
}




// complexity => copy me haii 