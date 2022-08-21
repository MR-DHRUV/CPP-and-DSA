#include <iostream>
using namespace std;

class Base
{
protected: // private variables that can be inherited
    int a;

private:
    int b;
};

/* 
            |    Public Derivation   |    private derivation  |    protected derivation
            |                        |                        |
1 Private   |    Not interited       |     Not interited      |       Not interited              
2 Protected |    Protected           |     Private            |       Protected 
3 Public    |    Public              |     Private            |       Protected

*/

class Derived : protected Base
{

};

int main()
{
    Base b;
    Derived d;
    
    // cant be printed directly 
    // function se hi hoga jaise private me karte the
    // cout<<d.a;
    // cout<<b.a;

    return 0;
}