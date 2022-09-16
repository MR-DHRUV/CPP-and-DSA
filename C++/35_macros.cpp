#include <iostream>
#define PI 3.14
#define AREA(l, b) (l * b)

#define ELE 1, 2, 3

// multiline macro
#define A 1, \
          2, \
          3

using namespace std;




// small functions ko inline bnalo (1 ya 2 line ke small hote hain)
inline int sum1(int a, int b)
{
    return a + b;
}
// inline functions are macros , thus they get replaced with code during compile time
// no extra memory usage to make copy of arguments and sames some time



int main()
{
    // macros are preffered over global variables as the dont use memory
    // macro is a piece of code in a program that is replaced by its value in a program

    // compile hone se pahle jaha jaha PI likha hoga wo 3.14 se replace ho jayga

    float area = PI * 3 * 3;

    cout << PI << endl;
    cout << area << endl;

    int a = AREA(2, 3);

    int arr[] = {ELE};

    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }

    // ternary operator
    a > 3 ? a = 0 : a = 1000;

    cout << a << endl;

    return 0;
}