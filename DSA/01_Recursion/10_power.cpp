#include <iostream>
using namespace std;

int powerCalc(int base, int power)
{

    if (power <= 0)
    {
        return 1;
    }

    else
    {
        return powerCalc(base, power - 1) * base;
    }
}

// more efficient
int powerCalcEfficient(int base, int power)
{

    if (power <= 0)
    {
        return 1;
    }

    else if(power%2 == 0){

        return powerCalcEfficient(base*base,power/2);
    }

    else
    {
        return powerCalcEfficient(base*base, (power-1)/2) * base;
    }
}

int powerCalcLoop(int base , int power){

    long long int pow = 1;

    while (power > 0)
    {
        pow *= base;
        power --;
    }
    
    return pow;
}





int main()
{
    cout << powerCalcEfficient(5, 0) << endl;
    cout << powerCalcEfficient(5, 1) << endl;
    cout << powerCalcEfficient(5, 2) << endl;
    cout << powerCalcEfficient(5, 3) << endl;
    cout << powerCalcEfficient(5, 4) << endl;
    cout << powerCalcEfficient(5, 5) << endl;
    cout << powerCalcEfficient(5, 6) << endl;

    cout << powerCalc(5, 0) << endl;
    cout << powerCalc(5, 1) << endl;
    cout << powerCalc(5, 2) << endl;
    cout << powerCalc(5, 3) << endl;
    cout << powerCalc(5, 4) << endl;
    cout << powerCalc(5, 5) << endl;
    cout << powerCalc(5, 6) << endl;

    cout << powerCalcLoop(5, 0) << endl;
    cout << powerCalcLoop(5, 1) << endl;
    cout << powerCalcLoop(5, 2) << endl;
    cout << powerCalcLoop(5, 3) << endl;
    cout << powerCalcLoop(5, 4) << endl;
    cout << powerCalcLoop(5, 5) << endl;
    cout << powerCalcLoop(5, 6) << endl;
    
    return 0;
}
