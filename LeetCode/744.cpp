#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int start = 0;
        int end = letters.size() -1;


    
        while(start <= end)
        {
            
            // might be possible that start + end exceed limit of int so
            int mid = start + (end-start) / 2;

            if(letters[mid] > target){
                
                end = mid -1;
            }

            else
            {
                start = mid +1;
            }

        }

        // %lettes.size() isilie kiya taaki kabhi start gar bahar nikal jaye array se , index n pe aajay toh return toh 0 krna hoga toh n % n = 0 hoga 
        return letters[start % letters.size()];
    }
};
