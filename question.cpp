#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void print(vector<int> arr)
    {
        for (int &i : arr)
            cout << i << " ";
        cout << endl;
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int avg(int i, int j, vector<vector<int>> &image)
    {
        int sum = 0;
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
                sum += image[i - x][j - y];
        }

        return sum / 9;
    }

public:
    vector<vector<int>> resultGrid(vector<vector<int>> &image, int threshold)
    {
        vector<vector<int>> ans(image.size(), vector<int>(image[0].size(), -1));

        // process regions
        // i and j points to end points of submatrices
        for (int i = 2; i < image.size(); i++)
        {
            for (int j = 2; j < image[0].size(); j++)
            {
                // traversing the region: O(1)
                int i_end = i - 3, j_end = j - 3;
                int sum = 0;

                bool isValid = 1;
                for (int s = i; s > i_end && isValid; s--)
                {
                    for (int t = j; t > j_end && isValid; t--)
                    {
                        sum += image[s][t];

                        // checking validity
                        for (int k = 0; k < 4; k++)
                        {
                            int x = s + dx[k], y = t + dy[k];

                            // check if x and y belong to region
                            if (x > i_end && x <= i && y > j_end && y <= j && abs(image[i][j] - image[x][y]) > threshold)
                            {
                                isValid = 0;
                                break;
                            }
                        }
                    }
                }

                if (isValid)
                {
                    sum /= 9;
                    for (int x = i; x > i_end; x--)
                    {
                        for (int y = j; y > j_end; y--)
                        {
                            if (ans[x][y] == -1)
                                ans[x][y] = sum;
                            else
                                ans[x][y] = (ans[x][y] + sum) / 2;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < image.size(); i++)
        {
            for (int j = 0; j < image[0].size(); j++)
            {
                if (ans[i][j] == -1)
                    ans[i][j] = image[i][j];
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}