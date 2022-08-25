#include <iostream>
using namespace std;

// anagram are two set of strings formed by using same set of words;
// eg : decimal and medical

// cheching anagram

//  we can do so in 2 steps
//  1. checking element at index 0, to make sure they are not same
//  2. checking strings are same , not comparing 2 strings but comparing elements in them

int length(string str)
{

    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

// for lowercase elements
int areElementSame(string str1, string str2)
{
    // init hash table
    int strlen = length(str1);
    int strlen1 = length(str2);

    if(strlen != strlen1){
        return 0;
    }
    

    int H[strlen] = {0};

    for (int i = 0; i < strlen; i++)
    {
        H[((int)str1[i] - 97)]++;
    }

    for (int j = 0; j < strlen; j++)
    {
        H[((int)str1[j] - 97)]--;
    }

    for (int k = 0; k < strlen; k++)
    {
        if (H[k] != 0)
        {
            return 0;
        }
    }

    return 1;
}

int areAnagram(string str1, string str2)
{
    int check = areElementSame(str1, str2);

    if (check == 1)
    {
        return 1;
    }

    return 0;
}

int main()
{
    string str1 = "abcddc";
    string str2 = "dcdbca";

    cout<<areAnagram(str1, str2);

    return 0;
}