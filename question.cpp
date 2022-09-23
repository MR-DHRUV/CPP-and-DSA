#include<bits/stdc++.h>
using namespace std;

int equalParity(vector<int> &v, int k){
    
    int odd = 0;
    int even = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if(v[i]%2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    
    if(odd > even)
    {
        if(k <= even)
        {
            return odd+k;
        }
    }
    else
    {
        if(k <= odd)
        {
            return even+k;
        }
    }

    return odd+even;
}

int main()
{
    
    return 0;
}