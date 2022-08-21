#include <iostream>
using namespace std;

// destructor never takes argument or never returns a value;
static int count;

class Num
{

public:
    Num()
    {
        count++;
        cout << "Constuctor is called fot object no" << count << endl;
    };
    // jaise default constructtor milta h waise hi distructor bhi milta haii
    // distructor;
    ~Num()
    {
        cout << "Distructor is called for object no" << count << endl;
        count--;
    }
};

int main()
{

    cout << "Creating first object" << endl;

    Num n1;
    {
        cout << "entering this block" << endl;
        cout << "Creating two more objects" << endl;
        Num n2, n3;

        cout << "exiting this block" << endl;
    }

    cout << "back to main" << endl;

    return 0;
}