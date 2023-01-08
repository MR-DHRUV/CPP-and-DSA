#include<bits/stdc++.h>
using namespace std;

class HashTable
{
    int *H;

public:
    int modVal;

    HashTable(){};
    HashTable(int x) : modVal(x)
    {
        H = new int[modVal]{-1};
    };

    int Hash(int key)
    {
        return key % modVal;
    }

    void insert(int key)
    {
        int index = Hash(key);
        
    }

    // bool search(int key)
    // {
    //     int index = Hash(key);
    //     Node *isPresent = searchList(H[index], key);

    //     if (isPresent == NULL)
    //     {
    //         return false;
    //     }

    //     return true;
    // }
};

int main()
{
    // closed hashing based collision resolution technique
    // we'll not use any extra space like we did in open hashing
    // here we can only insert elements equal to size of hash table so loading factor is always less than or equal to 1

    // idealy loading factor must be <= 0.5, i.e we must not fill hash table more than half 

    // here we have a modified hash function to do linear probing
    // h(x) = x%mod_size
    // h'(x) = (h(x)+f(i))%mod_size
    // f(i) = i 

    // Average successfull search
    // t = (1/lamda) * log(1/1-lamda) 

    // Average unsuccessfull search
    // t = 1/1-lamda

    // deletion
    // using hash function find the key and delete it
    // we have to shift all the elements after it so that we can search elements after it
    // we only have to shift that keys are kept there due to lack of space
    // keys at their correct location must not be shifted
    // we have to delete the given key and then insert all the values one by one in the table, it is called as rehashing
    // Thus in linear probing we dont suggest deletion of keys

    // Disadvantage
    // 1 space wastage as we can fill atmost half of the table
    // 2 Primary cluster : group of keys are togher at one place
    // eg 5 , 15, 25, 35 will aggregate at one place
    // 3 complex and slow deletion




    return 0;
}