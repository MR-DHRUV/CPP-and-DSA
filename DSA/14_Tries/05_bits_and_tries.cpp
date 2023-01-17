#include<bits/stdc++.h>
using namespace std;


class TrieNode
{
    public : 
    // each node can have
    TrieNode *children[2];
};

int main()
{
    // 9 -> 1001
    // in computer 0000......1001 ie either 32 or 64 bits

    // XOR related problems
    // we are given an array of numbers ans a number x, we have to find the max value of arr[i]^x
    
    // Approach
    // step 1 : insert all the numbers into the trie in binary format with 32/64 bits starting from msb
    // step 2 : find maximum no that we can possibly make

    // eg we x = 10000101
    // for 1 we will find 0 if not found no other option we have to take 1 only
    // for 0 we will find 1 as 1^0 = 1 
    // repreat the process for all bits
    // we''ll start from msb as if we could set msb our ans will be max 

    // if we have 2 arrays ans need to find max xor
    // 1 ko trie me daaldo
    // 2 nd ke keys 1-1 kerke check krlo
    // return max value found


    return 0;
}