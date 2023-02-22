#include <iostream>
#include <iomanip>
using namespace std;

ostream &curr(ostream &ostrObj)
{
    cout << setprecision(5);
    cout << "Rs.";
    return ostrObj;
}

int main()
{
    float amt = 10.5478;
    cout << curr << amt;
    return 0;
}
