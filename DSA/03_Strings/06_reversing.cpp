#include <iostream>
using namespace std;

int length(char str[])
{

    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

void reverse(char str[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        swap(str[s++], str[e--]);
    }
}

int main()
{
    // strings are imutable so use char arrays

    char str[20] = {'D', 'H', 'R', 'U', 'V'};

    cout << str << endl;

    reverse(str, length(str));

    cout << str << endl;

    return 0;
}