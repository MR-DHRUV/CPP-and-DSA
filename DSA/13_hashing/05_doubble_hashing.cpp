#include <bits/stdc++.h>
using namespace std;

class HashTable
{
    int *H;

public:
    int modVal;
    int R;

    HashTable(){};
    HashTable(int x, int r) : modVal(x), R(r)
    {
        H = new int[modVal];
        for (int i = 0; i < modVal; i++)
        {
            H[i] = -1;
        }
    };

    // this is hash function
    int Hash1(int key)
    {
        return key % modVal;
    }

    // this is compression function
    // the value of r is kept high to provide a uniform distribution
    int Hash2(int key)
    {
        return R - (key % R);
    }

    void printArr()
    {
        for (int i = 0; i < modVal; i++)
        {
            cout << H[i] << " ";
        }

        cout << endl;
    }

    // used for finding next free slot
    int probe(int key)
    {
        int index = Hash1(key);
        int i = 1;

        while (H[Hash1(index + (i * Hash2(key)))] != -1 && i < modVal)
        {
            i++;
        }

        // ghum kr index pr aagaya aur index occuppied haii
        if (i >= modVal && H[i] != -1)
        {
            return -1;
        }

        return Hash1(index + (i * Hash2(key)));
    }

    void insert(int key)
    {
        int index = Hash1(key);

        // checking that slot is free or not
        if (H[index] != -1)
        {
            index = probe(key);
            if (index == -1)
            {
                cout << "Hash table is full" << endl;
                return;
            }
        }

        H[index] = key;
    }

    bool search(int key)
    {
        int index = Hash1(key);
        int i = 0;

        while (H[Hash1(index + (i * Hash2(key)))] != key && i < modVal)
        {
            i++;
        }

        if (H[Hash1(index + (i * Hash2(key)))] == key)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    // we'll have a primary hash function and whenever we'll have a collision then the other hash function will help us

    // h1(x) = x%mod_value
    // h2(x) = R - (x%R);
    // here R is the largest prime no smaller than the mod_value

    // h2 has 2 desired characterstics
    // 1 it will never give a result 0
    // 2 it will try to probe all the locations
    // thus whenever there's a collision indices are generated in different pattern

    // probe function
    // h'(x) = (h1(x) + i*h2(x))% mod_value

    HashTable ht(10,7);
    ht.printArr();
    ht.insert(5);
    ht.insert(25);
    ht.insert(15);
    ht.insert(35);
    ht.insert(95);

    ht.printArr();

    cout << ht.search(3) << endl;
    cout << ht.search(25) << endl;

    return 0;
}