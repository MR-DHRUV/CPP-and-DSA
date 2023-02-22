#include<bits/stdc++.h>
using namespace std;



int main()
{
    int x = 5, y = 0;

    try
    {
        if(y == 0)
        {
            throw y;
        }

        x = x/y;
    }
    catch(int y)
    {
        cout<<"Cant divide by 0"<<endl;
    }



    return 0;
}