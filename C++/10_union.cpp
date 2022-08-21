#include <iostream>
using namespace std;

union money
{
    int rice;
    char car;
    float pound;
};
// in teno me se ek time pe ek hi use kar skte ho

int main()
{
    union money m1;
    m1.rice = 34;
    m1.car = 'c';

    cout << m1.rice << endl;
    cout << m1.car << endl;
    // two use kare hain isliye 1st wale ki garbage value milli haii

    union money m2;

    m2.rice = 344;
    cout << m2.rice << endl;

    return 0;
}