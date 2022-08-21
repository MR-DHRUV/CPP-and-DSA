#include <iostream>
using namespace std;

class shop
{
    int id;
    double price;

public:
    void set_data(int a, int b)
    {
        id = a;
        price = b;
    };
    void get_data()
    {
        cout << "The id is " << id << " and is price is " << price << endl;
    }
};

int main()
{
    int size = 3;

    // dynamic memory to store 34 integer
    int *ptrDynamicAlloc = new int[34];

    // shop of 3 items
    shop *ptr = new shop[size];

    shop *copyToPtr = ptr;

    // syntax 1
    // ptr->set_data(2,3);
    // ptr[0].get_data();
    // ptr[1].get_data();

    // auto sequencial input
    // for (int i = 0; i < size; i++)
    // {

    //     ptr->set_data((i + 1), ((i + 1) * 10));
    //     ptr->get_data();
    //     ptr++;
    // }

    for (int i = 0; i < size; i++)
    {
        int id;
        double price;
        cout << "Enter id and price of item " << (i + 1) << endl;
        cin >> id >> price;
        ptr->set_data(id, price);
        ptr++;
    }

    for (int j = 0; j < size; j++)
    {
        (copyToPtr)->get_data();
        copyToPtr++;
    }

    return 0;
}