#include<bits/stdc++.h>
using namespace std;



int main()
{
    // hash function
    // it is a combination of hash generator and compression function
    // compression function ensures that the given value is never out of range
    // % acts as a compression fucntion


    // types of hash functions
    // mod
    // midsquare
    // folding

    // a function should be selected such that 
    // the values in hash table are uniformly distributed
    
    // size of hash table should be prime in order to reduce collisions


    // Midquare method
    // eg : we need index of 11
    // (11)2 = 121 take the middle digit and store it at that index i.e 2
    // we can use n middle digits according to size of our hash table

    // Folding method
    // eg: key = 123347
    // index = 12 + 33 + 47 = 92
    // for keys like abc we can use their ascii values 


    return 0;
}