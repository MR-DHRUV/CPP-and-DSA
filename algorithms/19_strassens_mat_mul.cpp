#include <bits/stdc++.h>
using namespace std;

// Native algo : O(n3)
vector<vector<int>> matMul(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
{
    vector<vector<int>> ans(2, vector<int>(2, 0));

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                ans[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return ans;
}

vector<vector<int>> strassens(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
{
    vector<vector<int>> ans(2, vector<int>(2, 0));

    // we will break the matrix until they are of base size and we will only multiply base size matrices

    // base case : multiplying two 2*2 matrices : O(1) 

    // if we have a matrix of order such that it is not of power of 2 then we will make it a square matrix of order of power of 2 and we will fill the remaning elements with 0

    
}




int main()
{
    
    
    return 0;
}