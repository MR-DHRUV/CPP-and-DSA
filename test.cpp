#include <iostream>
using namespace std;

int main()
{
    int XOR = 5^1;
    int Sn = XOR & ~(XOR - 1);

    cout<<Sn;
    cout<<XOR;

    return 0;
}