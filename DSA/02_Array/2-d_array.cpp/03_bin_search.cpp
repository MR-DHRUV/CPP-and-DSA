#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    // this is for row only sorted matrix like this
    // 0 1 2
    // 3 4 5
    // 6 7 8

    // here last element of each row is smaller than first element of next row 
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = row * col - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            // imagine it as a 2-d array with n linear elements,index of any element at index mid in linear form, in 2-d will by given as follows

            // mid/col returns the row no in which element at index mid is present
            // mid%col returns the column no
            int element = matrix[mid / col][mid % col];

            if (element == target)
            {
                return true;
            }

            else if (element > target)
            {
                end = mid - 1;
            }

            else
            {
                start = mid + 1;
            }
        }
    }
};



class Solution1 {
public:


    /* 
    
    row and column both soted

     1, 4, 7,11,15
     2, 5, 8,12,19
     3, 6, 9,16,22
    10,13,14,17,24
    18,21,23,26,30
    
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
    
        int row = matrix.size();
        int col = matrix[0].size();
        
        int rowIndex = 0;
        int colIndex = col-1;
        
        while(rowIndex < row && colIndex >= 0)
        {
            int element = matrix[rowIndex][colIndex];
            
            if(element == target)
            {
                return true;
            }
            
            else if(element < target)
            {
                rowIndex++;
            }
            else
            {
                colIndex--;
            }
            
        }
        
        return false;
        
    }
        
};

int main()
{
    // binary search in 2-d array;

    return 0;
}