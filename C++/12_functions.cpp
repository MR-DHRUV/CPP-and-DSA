#include <iostream>
using namespace std;

int sum(int a, int b)
{
    return a + b;
}

// small functions ko inline bnalo (1 ya 2 line ke small hote hain)
inline int sum1(int a, int b)
{
    return a + b;
}
// inline functions are macros , thus they get replaced with code during compile time
// inline functions are macros , thus they get replaced with code during compile time
// no extra memory usage to make copy of arguments and sames some time



// function prototype
//type function-name(arguments);
// it assures program in main that it will find that function somewhare in the program

int multiply(int a, int b);

int main()
{
    int c = sum(2, 4);
    cout << c << endl;
    
    
    
    return 0;

}


int multiply(int a, int b)
{
    return a * b;
}