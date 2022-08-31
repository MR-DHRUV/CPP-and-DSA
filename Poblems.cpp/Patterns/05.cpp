#include<iostream>
using namespace std;

int main()
{
     int n ;
    cin>>n;

    int i = 0;

    while ( i < n)
    {
        int j = i;

        while ( j >= 0)
        {
            cout<<(j+1);
            j--;
        }
        cout<<endl;
        i++;
    }
    
    return 0;
}