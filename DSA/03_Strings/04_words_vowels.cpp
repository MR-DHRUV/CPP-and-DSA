#include <iostream>
using namespace std;

void strInfo(string str)
{
    int words = 0;
    int vowels = 0;
    int i = 0;

    while (str[i] != '\0')
    {

        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            vowels++;
            i++;
        }
        else
        {
            words++;
            i++;
        }
    }

    cout << "Vowels : " << vowels << endl;
    cout << "Words : " << words << endl;
}

int main()
{
    string name = "Dhruv";
    strInfo(name);

    return 0;
}