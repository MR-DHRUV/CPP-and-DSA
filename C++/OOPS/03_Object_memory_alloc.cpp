#include <iostream>
using namespace std;

class Shop
{
    int itemId[100];
    int itemPrice[100];
    int counter;

public:
    void initCounter(void) { counter = 0; }
    void getPrice(void);
    void setPrice(void);
};

void Shop ::setPrice()
{
    cout << "Enter Id of your item no " << (counter + 1) << endl;
    cin >> itemId[counter];
    cout << "Enter price of your item no" << (counter + 1) << endl;
    cin >> itemPrice[counter];
    counter++;
}

void Shop ::getPrice()
{
    for (int i = 0; i < counter; i++)
    {
        cout << "The price of item with Item-Id " << itemId[i] << " is " << itemPrice[i] << endl;
    }
}

int main()
{
    Shop dukaan;
    dukaan.initCounter();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.getPrice();

    return 0;
}