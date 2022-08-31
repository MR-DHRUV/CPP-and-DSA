#include <iostream>
using namespace std;

int main()
{

    return 0;
}

class Solution
{
public:
    int reverse(int x)
    {
        int ans;

        while (x != 0)
        {
            int digit = x % 10;

            if(ans > INT32_MAX / 10 || ans < INT32_MIN/10)
            {
                return 0;
            }

            ans = (ans * 10) + digit;

            x = x / 10;
        }

        return ans;
    }
};
