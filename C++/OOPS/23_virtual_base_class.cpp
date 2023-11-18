#include <iostream>
using namespace std;

//  virtul base classes ke elements inherit hone se pahele check karenge ki uss name ka koi aur member toh nahi haii
// agar hoga toh inherit nahi hoga warna ho jayga
// thus it resolves ambiquity

// syntax

class student
{

protected:
    int roll_no;
 
public:
    void set_roll(int a)
    {
        roll_no = a;
    };
    void print_no()
    {
        cout << "roll no is " << roll_no << endl;
    };
};

// virtual base class
class test : virtual public student
{
protected:
    double maths;
    double physics;

public:
    void set_marks(double a, double b)
    {
        maths = a;
        physics = b;
    }
    void get_marks()
    {
        cout << "marks of roll no " << roll_no << " is " << endl;
        cout << "Physics " << physics << endl;
        cout << "Maths " << maths << endl;
    }
};

class sports : virtual public student
{
protected:
    double score;

public:
    void set_score(double a)
    {
        score = a;
    }
    void get_score()
    {
        cout << "Score of roll no " << roll_no << " is " << score << endl;
    }
};

class result : public test, public sports
{
    float total;

public:
    void get_result()
    {
        total = maths + physics + score;
        get_marks();
        get_score();
        cout << "The result is " << (total / 3) << endl;
    }
};

int main()
{   
    result Dhruv;
    Dhruv.set_roll(28);
    Dhruv.set_marks(100,99);
    Dhruv.set_score(98);
    Dhruv.get_result();
    return 0;
}
