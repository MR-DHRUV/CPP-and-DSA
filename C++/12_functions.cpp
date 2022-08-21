#include <iostream>
using namespace std;

int sum(int a, int b)
{
    return a + b;
}

// function prototype
//type function-name(arguments);
// it assures program ninmain that it will find that function somewhare in the program

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