#include<bits/stdc++.h>
using namespace std;


//euclids algo
// gcd(a,b) = gcd(a-b,b) = gcd(a%b,b)


// lcm(a,b) * gcd(a,b) = a*b

int gcd(int a , int b)
{
    if(a==0)
    {
        return b;
    }
    if(b==0)
    {
        return a;
    }

    while (a != b)
    {
        if(a > b)
        {
            a = a-b;
        }
        else
        {
            b = b-a;
        }
    }

    return a;
    
  
}



int main()
{
    
    cout<<gcd(30,40)<<endl;
    
    return 0;
}