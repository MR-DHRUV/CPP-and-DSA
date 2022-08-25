#include <iostream>
using namespace std;

int length(string str)
{

    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}


// incedible solution by dhruv
void permutation(string str)
{

    int n = length(str);

    int fac = 1;

    for (int i = 0; i < n; i++)
    {
        fac = fac * (i + 1);
    }
    fac--;

    int iter = 0;
    cout << str << endl;
    for (int j = 0; j < fac; j++)
    {

        if (iter == n - 1)
        {
            iter = 0;
        }

        char temp = str[iter];
        str[iter] = str[iter + 1];
        str[iter + 1] = temp;
        cout << str << endl;
        iter++;
    }
}

int main()
{

    string str = "ABCD";
    permutation(str);

    return 0;
}