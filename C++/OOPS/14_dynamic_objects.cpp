#include <iostream>
using namespace std;

class BankDeposit
{
    int principal;
    int years;
    float intrestRate;
    float returnValue;

public:
    BankDeposit(){};
    BankDeposit(int p, int y, float r);
    // is rate of itrest can be integer or float depending upon user input 0.04 <-> 4%
    BankDeposit(int p, int y, int r);
    void getBalance()
    {
        cout << "The return value is " << returnValue << endl;
    };
};

BankDeposit ::BankDeposit(int p, int y, float r)
{
    principal = p;
    years = y;
    intrestRate = r;
    returnValue = p;

    for (int i = 0; i < y; i++)
    {
        returnValue = (returnValue) * (1 + intrestRate);
    }
};

BankDeposit ::BankDeposit(int p, int y, int r)
{
    principal = p;
    years = y;
    intrestRate = r;
    returnValue = p;

    for (int i = 0; i < y; i++)
    {
        returnValue = (returnValue) * (1 + ((intrestRate) / 100));
    }
};

int main()
{
    BankDeposit acc1, acc2, acc3;

    int p, y;
    int R;
    float r;

    cout << "Enter the value of p y and r" << endl;
    cin >> p >> y >> r;

    acc1 = BankDeposit(p, y, r);
    acc1.getBalance();

    cout << "Enter the value of p y and R" << endl;
    cin >> p >> y >> R;

    acc2 = BankDeposit(p, y, R);
    acc2.getBalance();

    return 0;
}