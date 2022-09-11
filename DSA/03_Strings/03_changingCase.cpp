#include<bits/stdc++.h>
using namespace std;

// diffrence 32
// lowercase +
// uppercase -

void toUpper(char *ptr)
{
    while (*ptr != '\0')
    {
        if (int(*ptr) > 96)
        {
            *ptr = char(int(*ptr) - 32);
            ptr++;
        }
        else
        {
            ptr++;
        }
    }
}

void toLower(char *ptr)
{
    while (*ptr != '\0')
    {
        if (int(*ptr) < 97)
        {
            *ptr = char(int(*ptr) + 32);
            ptr++;
        }
        else
        {
            ptr++;
        }
    }
}

int main()
{
    string name = "Dhruv";
    char *ptr = &name[0];
    toUpper(ptr);
    cout << name << endl;

    toLower(ptr);
    cout << name << endl;

    char A[] = "AnameZ";
    toUpper(&A[0]);
    cout << A << endl;

    toLower(&A[0]);
    cout << A << endl;

    return 0;
}