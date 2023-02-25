#include<bits/stdc++.h>
using namespace std;



int main()
{
    // problem with hash maps
    // concider a hashmap of string to int
    // in the worst case a string like "abababababababaaaaaaabbbbbbbb" will take O(length of string) time for any operation

    // thus we need a new data structure

    // tries

    // advantage of trie
    // space is optimised 
    // suggesion de skta haii tries ki kon kon se words haii uske pass ek given input ke lie
    // Trees like BST B+ are suitable for storing data where keys are in the form of numbers while when the data is it be identified with characters Ties are optimal

    // It can be insert faster and search the string than hash tables and binary search trees. thus optimal for strings
    // It provides an alphabetical filter of entries by the key of the node.

    // Trie vs Hash Table
    /*
      1 Looking up data in a trie is faster in worst case as compared to imperfect hash table.
      2. There are no collisions of different keys in a trie.      
      3. Sometimes data retrieval from tries is very much slower than hashing.                  
    */


    
    return 0;
}