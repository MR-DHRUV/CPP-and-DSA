#include <bits/stdc++.h>
using namespace std;

class Solution
{   
    // co-ordinates from where a student can cheat so we cannot place a student here 
    const int cx[4] = {1, -1, 1, -1};
    const int cy[4] = {0, 0, 1, -1};

public:
    int maxStudents(vector<vector<char>> &seats)
    {
        // kuhn's algorithm
        // studnent can cheat from upper left, upper right, left , right
    }
};

int main()
{

    return 0;
}