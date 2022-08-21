#include <iostream>
using namespace std;

typedef struct Employee
{
    int Id;
    char favChar;
    long double salary;
} Employee; // type defined so that struct Employee na likhna pade

int main()
{
    struct Employee Harry;
    Harry.favChar = 'h';
    Harry.Id = 1;
    Harry.salary = 120000.50;

    cout << Harry.favChar << endl
         << Harry.salary << endl
         << Harry.Id << endl;

    // after defining type
    Employee Dhruv;

    Dhruv.favChar = 'd';
    Dhruv.Id = 2;
    Dhruv.salary = 999000.50;

    cout << Dhruv.favChar << endl
         << Dhruv.salary << endl
         << Dhruv.Id << endl;

    return 0;
}