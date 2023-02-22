#include <bits/stdc++.h>
using namespace std;

class HashTable
{
    int *H;

public:
    int modVal;

    HashTable(){};
    HashTable(int x) : modVal(x)
    {
        H = new int[modVal];
        for (int i = 0; i < modVal; i++)
        {
            H[i] = -1;
        }
    };

    int Hash(int key)
    {
        return key % modVal;
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
        int index = Hash(key);
        int i = 1;

        while (H[Hash(index + (i*i))] != -1 && i < modVal)
        {
            i++;
        }

        // ghum kr index pr aagaya aur index occuppied haii
        if (i >= modVal && H[Hash(index+(i*i))] != -1)
        {
            return -1;
        }

        return Hash(index + (i*i));
    }

    void insert(int key)
    {
        int index = Hash(key);

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
        int index = Hash(key);
        int i = 0;

        while (H[Hash(index + (i*i))] != key && i < modVal)
        {
            i++;
        }

        if (H[Hash(index + (i*i))] == key)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    // closed hashing based collision resolution technique
    // in linear probing there was an issue of clustering 

    // here we have a modified hash function to do quadratic probing
    // h(x) = x%mod_size
    // h'(x) = (h(x)+f(i))%mod_size
    // f(i) = i*i

    // Average successfull search
    // t = ln(1-lamda)/lamda

    // Average unsuccessfull search
    // t = 1/1-lamda

    // Disadvantage
    // 1 space wastage as we can fill atmost half of the table
    // 2 complex and slow deletion

    HashTable ht(10);
    ht.printArr();
    ht.insert(3);
    ht.insert(13);
    ht.insert(23);
    // ht.insert(3);

    ht.printArr();

    cout<<ht.search(3)<<endl;
    cout<<ht.search(23)<<endl;

    return 0;
}