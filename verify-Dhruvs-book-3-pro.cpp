#include <bits/stdc++.h>
#include <fstream>

using namespace std;

template <class T>
class LCG
{
    T _min;
    T _max;
    T _a;
    T _c;
    T _mod;
public:
    T _seed;

    LCG(T min, T max, T seed, T a, T c, T mod) : _min(min), _max(max), _seed(seed), _a(a), _c(c), _mod(mod){};

    T operator()()
    {
        // lgc function
        _seed = (_a * _seed + _c) % _mod;

        // bound to limit
        return (_seed % (_max - _min + 1)) + _min;
    }
};

template <class T>
class RandGen
{
public:
    void operator()(const string &filename, int len, LCG<T> &generator)
    {
        // Create a new file
        ofstream file(filename);

        // write first num as no of numbers in the file
        file<<len<<endl;

        // Generate the random numbers and write them to the file
        for (int i = 0; i < len; i++)
        {
            file << generator() << ",";
            // file << generator() << " ";
        }

        file.close();

        cout << "Generated " << len << " random numbers in " << filename << endl;
    }
};

int main()
{
    // init
    int arr[] = {50};
    int n = sizeof(arr) / sizeof(arr[0]);

    // init lcg function
    LCG<long long int> func(1,1e6,73412713494,329,71,759357937);

    // Generate files
    for (int i = 0; i < n; i++)
    {
        RandGen<long long int> generator;
        generator("random_" + to_string(arr[i]) + ".txt",arr[i],func);
    }

    return 0;
}
