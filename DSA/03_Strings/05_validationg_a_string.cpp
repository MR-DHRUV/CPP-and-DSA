#include <iostream>
using namespace std;

// for our case a valid string is a string having alphabets and numbers only

// 65-90
// 97-122
// 48 - 57

bool isValid(string str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (!(47 < int(str[i]) && int(str[i]) < 58) && !(64 < int(str[i]) && int(str[i]) < 91) && !(96 < int(str[i]) && int(str[i]) < 123))
        {
            return false;
        }
        else
        {
            i++;
        }
    }

    return true;
}

int main()
{
    string name = "aAzZ09";
    cout << isValid(name) << endl;

    return 0;
}