#include <bits/stdc++.h>
using namespace std;

int main()
{
    // disable default 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // set our properties
    #ifndef IO_FROM_FILE
    freopen("36_in.txt","r",stdin);
    freopen("36_out.txt","w",stdout);
    #endif


    // code

    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin>>a>>b;
        cout << a + b << endl;
    }

    return 0;
}