#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 0;
    int prev = 1;

    while (i < n)
    {
        int j = 0;

        while (j <= i)
        {
            cout << (j + 1);
            j++;
        }

        j--;

        while (j > 0)
        {
            j--;
            cout << (j + 1);
        }

        cout << endl;
        i++;
    }

    return 0;
}