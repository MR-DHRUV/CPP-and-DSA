#include <iostream>
using namespace std;


class Employee
{

    int id;
    static int count; // default value is 0 (static h isliye)
    // yaha pr value nahi di ja skti , ya toh member bana ke do ya phir :: isse do

public:
    void setData()
    {
        cout << "Enter the employee id" << endl;
        cin >> id;
        count++;
    };
    void getData()
    {
        cout << "The id of employee is " << id << " and this is employee no " << count << endl;
    };

    // isko member ki need nahi haii , class ke name se chalega
    static void getCount(void){
        cout<<"The count is "<<count<<endl;
    }
};


int Employee ::count; // bahar isliye likha taak taaki puri class ke liye ek hi count ho , alag alag member ka apna count na ho


int main()
{
    Employee Harry, Dhruv, Akshit;

    Harry.setData();
    Harry.getData();
    Employee::getCount();

    Dhruv.setData();
    Dhruv.getData();
    Employee::getCount();

    Akshit.setData();
    Akshit.getData();
    Employee::getCount();


    return 0;
}