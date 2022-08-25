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

bool compare(string str1, string str2)
{
    int i = 0;
    while (str1[i] != '\0')
    {
        if(str1[i] != str2[i]){
            return false;
        }

        i++;
    }
    return true;
}



int main()
{
    string str1 = "Dhruv";
    string str2 = "Dhruv";

    cout<<compare(str1,str2)<<endl;

    return 0;
}