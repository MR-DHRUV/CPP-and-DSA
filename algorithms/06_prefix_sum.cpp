#include<bits/stdc++.h>
using namespace std;

// prefix sum
// arr          = 6 3 -2 4 -1 0 -5
// prefixSumarr = 6 (6+3)=9 (9-2)=7 ...

// arr          = 6 3 -2  4 -1  0 -5
// prefixSumarr = 6 9  7 11 10 10  5

// we can calculae sum in any range using formula
// sum(i,j) = sum(j) - sum(i-1);

vector<int> prefixSum(vector<int> arr)
{
    vector<int> ans;
    
    ans.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        ans.push_back(arr[i] + ans.back());
    }

    return ans;
}

void printArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" "; 
    }

    cout<<endl;
    
}


int main()
{
    vector<int> a = {6,3,-2,4,-1,0,-5};
    vector<int> b = prefixSum(a);
    printArr(b);
    
    return 0;
}