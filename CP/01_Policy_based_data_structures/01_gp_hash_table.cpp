#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

// reffer notion for why custom hash function and why to use over unordered_map
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    // this fixed constant will change everytime as program proceeds inducing randomness
    // to further minimize the chance of hacking we use splitMix64 hashing algo
    size_t operator()(uint64_t x) const
    {
        // FIXED_RANDOM is initialized with the current time since the epoch (in nanoseconds)
        // epoch means starting point
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

__gnu_pbds::gp_hash_table<int, int, custom_hash> mp;

int main()
{
    // fast hash table

    return 0;
}