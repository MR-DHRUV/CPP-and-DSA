#include <iostream>
using namespace std;

// using hash table
// works only for eith lowercase or upprcase
// this is for lower case
void isDuplicate(string str)
{
    // 26 alphabets hain
    int H[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i = 0;

    while (str[i] != '\0')
    {
        H[(int)str[i] - 97] += 1;
        i++;
    }

    cout << "Duplicates are" << endl;

    for (int j = 0; j < 26; j++)
    {
        if (H[j] > 1)
        {
            cout << char(j + 97) << endl;
        }
    }

    // time complexity : O(n)
}

// bitwise operation

void duplicateBitwise(string str)
{
    // 4 byes with 0 at all places
    int H = 0;

    int i = 0;

    // 1 check if byte at ASCII-97 is 1 or not by masking;
    // if not then set it 1 by merging

    while (str[i] != '\0')
    {

        // checking on or not
        int whereTocheck = 1;
        whereTocheck = whereTocheck << ((int)str[i] - 97);

        int check = whereTocheck & H;
        // cout<<"Check for : "<<str[i]<<" is "<<check<<endl;

        if (check > 0)
        {
            cout << str[i] << endl;
        }
        else
        {
            H = H | whereTocheck;
        }

        i++;
    }
}

int main()
{
    string name = "lfetstsetswdqawrell";
    // isDuplicate(name);
    duplicateBitwise(name);

    return 0;
}