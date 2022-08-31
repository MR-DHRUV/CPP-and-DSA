#include <iostream>
#include <vector>

using namespace std;

vector<int> getBinArr(int n)
{

    vector<int> arr = {0, 0, 0, 0, 0, 0, 0, 0};

    if (n < 0)
    {
        arr[0] = 1;
    }

    n = abs(n);

    int i = 7;
    while (n != 0)
    {
        arr[i] = n & 1;
        i--;
        n = n >> 1;
    }
    return arr;
}

int getBin(int n)
{
    int result = 0;

    int calc = 1;

    while (n != 0)
    {
        result += calc * (n & 1);
        calc *= 10;
        n = n >> 1;
    }

    return result;
}


int getBinReverse(int n)
{
    int result = 0;
    n = abs(n);
    while (n != 0)
    {
        result = result * 10 + ((n&1));
        n = n >> 1;
    }

    return result;
}

int getBinSigned(int n)
{
    int result = 0;

    int calc = 1;

    if (n < 0)
    {
        // two's compliment
        int a = (getBinReverse(n));
        return a;
    }

    else
    {

        while (n != 0)
        {
            result += calc * (n & 1);
            calc *= 10;
            n = n >> 1;
        }

        return result;
    }
}

int getDecimal(int n)
{
    int t = 1;
    int result = 0;

    // we dont need to get the bit 
    // in reverse conversion we need to get the digit

    // to obtain the digits
    // ans = digit % 10 ; will give the last digit
    // to get prev digit = digit / 10;

    while (n != 0)
    {
        result = result + (t * (n%10)) ;
        t = t * 2;
        n /= 10 ;
    }

    return result;
}

int getNo(vector<int> arr)
{
    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans *10 + arr[i];
    }
    
    return ans;

}

int main()
{
    // int n = 5;

    // vector<int> arr = getBinArr(-11);

    // for (int i = 0; i < 8; i++)
    // {
    //     cout << arr[i] << ' ';
    // }
    // cout << endl;

    cout << getDecimal(10101) << endl;
    // cout << getBin(-11) << endl;
    // cout << getBinReverse(11) << endl;


    vector <int> arr = {1,2,3,4,5,6,7,8,9};


    cout<<getNo(arr)<<endl;
    cout<<getBin(123);

    return 0;
}