#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 

int equalParity(vector<int> &v, int k){
    
    int odd = 0;
    int even = 0;

    int maxOdd = 0;
    int maxEven = 0;

    for (int i = 0; i < v.size(); i++)
    {

        if(v[i]%2 == 0)
        {
            even++;
        }
        else
        {
            if(even > maxEven)
            {
                maxEven = even;
            }
            even =0;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {

        if(v[i]%2 != 0)
        {
            odd++;
        }
        else
        {
            if(odd > maxOdd)
            {
                maxOdd = odd;
            }
            odd =0;
        }
    }
    
    // if(odd > even)
    // {
    //     if(k <= even)
    //     {
    //         return odd+k;
    //     }
    // }
    // else
    // {
    //     if(k <= odd)
    //     {
    //         return even+k;
    //     }
    // }

    int maxCount = max(maxEven,maxOdd);

    if(k >= v.size() || maxCount+k >= v.size())
    {
        return v.size();
    }

    return maxCount+k;
}


int main()
{
    
    return 0;
}