//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long arr[], int n)
    {

        //prefix sum approach 
        // last aur start se krta haii sum 
        // jaise hi dono equal ho jate hain aur no of iterations total elements-1 ke equal ho jati hain toh ans aajata haii 

        if (n == 1)
        {
            return 1;
        }

        int i = 0;
        int j = n - 1;

        int ci =1;
        int cj = 1;

        while (i <= j)
        {
            if (arr[i] == arr[j] && ci + cj == n-1)
            {
                return j - i + 1;
            }

            else if(arr[i] == arr[j] && ci + cj < n-1)
            {
                j--;
                cj++;
                arr[j] = arr[j] + arr[j + 1];
                i++;
                ci++;
                arr[i] = arr[i] + arr[i - 1];
            }

            else if (arr[i] > arr[j])
            {
                j--;
                cj++;
                arr[j] = arr[j] + arr[j + 1];
                cout <<"i "<<i<<"  "<< arr[i] << endl;
                cout <<"j "<<j<<"  "<< arr[j] << endl;
                cout<<ci<<" "<<cj<<endl<<endl;
            }
            else
            {
                i++;
                ci++;
                arr[i] = arr[i] + arr[i - 1];
                cout <<"i "<<i<<"  "<< arr[i] << endl;
                cout <<"j "<<j<<"  "<< arr[j] << endl;
                cout<<ci<<" "<<cj<<endl<<endl;
            }
        }

        return -1;
    }
};

//{ Driver Code Starts.

int main()
{

    long long t;

    // taking testcases
    cin >> t;

    while (t--)
    {
        long long n;

        // taking input n
        cin >> n;
        long long a[n];

        // adding elements to the array
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;

        // calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends