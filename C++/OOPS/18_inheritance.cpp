#include <iostream>
using namespace std;

// base class
class Employee
{
    float salary;

public:
    int id;
    Employee()
    {
        salary = 34;
    };
    Employee(int i)
    {
        id = i;
        salary = 34;
    };
    void getData(void)
    {
        cout << salary << " " << id << endl;
    }
};


// derived class
// class Programmer : visibility mode here Employee

// visibility mode can pe
// Default mode is private
// Public :  base class ke public members derived class ke public hi rehte hain
// Private : base class ke public members derived class ke private member ban jate hain

// You cannot inherit private members of base class, thus they are never inherited


class Programmer : public Employee
{
public:
    int languageCode = 9;
    Programmer(int i)
    {
        // id = i  you cannot do this, as pehle id ko public karo
        id = i;
        // there should be a default contructor in the base class
    };
};


int main()
{
    Programmer skillF(3);
    skillF.getData();
    cout<<skillF.languageCode<<endl;

    return 0;
};