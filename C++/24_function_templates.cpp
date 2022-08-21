#include <iostream>
using namespace std;

template <class T1, class T2>
double funcAvg(T1 a, T2 b)
{
    double avg = (a + b) / 2;
    return avg;
}

int main()
{
    float a;

    // T1 and T2 is auto assigned in functions
    a = funcAvg(5, 3.3);
    cout << a << endl;

    return 0;
}