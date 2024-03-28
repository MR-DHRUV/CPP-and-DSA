#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random string of a given length
string generateRandomString(int length)
{
    // const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    // const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // const char charset[] = "abcdefghijklmnopqrstuvwxyz";
    // const char charset[] = "01234500006789";
    const char charset[] = "ABCBC";
    const int charsetSize = sizeof(charset) - 1;

    string randomString;
    for (int i = 0; i < length; ++i)
    {
        randomString.push_back(charset[rand() % charsetSize]);
    }

    return randomString;
}

int main()
{
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Input parameters
    int n = 1, m = 1000;

    for (int i = 0; i < n; ++i)
    {
        string randomString = generateRandomString(m);
        cout << randomString << endl;
    }

    return 0;
}
