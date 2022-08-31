#include<iostream>
using namespace std;

int main()
{
     int n ;
    cin>>n;

    int i = 0;
    int printer = 97;

    while ( i < n)
    {
        int j = 0;

        while ( j < n)
        {
            
            cout<<(char(printer+j));
            j++;
        }

        cout<<endl;
        printer++;
        i++;

    }
    
    return 0;
}