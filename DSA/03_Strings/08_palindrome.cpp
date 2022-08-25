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

bool isPalindrome(string str)
{
    int len = length(str) - 1;
    int i = 0;

    while (i < len)
    {

        if (str[i] != str[len])
        {
            return false;
        }

        i++;
        len--;
    }

    return true;
}

int main()
{
    string name = "Dhruv";
    cout<<isPalindrome(name);

    return 0;
}