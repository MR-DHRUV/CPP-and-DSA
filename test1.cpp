#include <iostream>
#include <vector>

using namespace std;

// Function to count combinations that make children happy
int countCombinations(vector<int> &gifts, int index, int superHappyCount)
{
    if (index == gifts.size())
    {
        return (superHappyCount > 0) ? 1 : 0;
    }

    // Try not giving the gift to the current child
    int combinationsWithoutGift = countCombinations(gifts, index + 1, superHappyCount);

    // Try giving the gift to the current child
    int combinationsWithGift = countCombinations(gifts, index + 1, superHappyCount + gifts[index]);

    // Return the sum of both cases
    return combinationsWithoutGift + combinationsWithGift;
}

int countHappyCombinations(int A, vector<int> &B)
{
    return countCombinations(B, 0, 0);
}

int main()
{
    int A1 = 2;
    vector<int> B1 = {2, 2, -1, 1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    int A2 = 3;
    vector<int> B2 = {1, 1, 3, 2, 2, 3, 1, 3, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    int result1 = countHappyCombinations(A1, B1);
    int result2 = countHappyCombinations(A2, B2);

    cout << "Input 1 - Number of happy combinations: " << result1 << endl;
    cout << "Input 2 - Number of happy combinations: " << result2 << endl;

    return 0;
}