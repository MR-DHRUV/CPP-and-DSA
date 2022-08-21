#include <iostream>
using namespace std;

class Student
{
protected:
    int roll_no;

public:
    void set_roll_no(int);
    void get_roll_no(void);
};

void Student ::set_roll_no(int r)
{
    roll_no = r;
};

void Student ::get_roll_no()
{
    cout << "The roll no is " << roll_no << endl;
};

class Exam : public Student
{
protected:
    double maths;
    double physics;

public:
    void set_marks(double, double);
    void get_marks();
};

void Exam ::set_marks(double a, double b)
{
    physics = a;
    maths = b;
};

void Exam ::get_marks()
{
    cout << "The marks of maths are " << maths << endl;
    cout << "The marks of physics are " << physics << endl;
};

class Result : public Exam
{
    double percentage;

public:
    void display(void);
};

void Result ::display(){
    cout<<"The percentage of roll no "<<roll_no<<" is "<<((maths+physics)/2)<<endl;
}


int main()
{
    // A --> B --> C

    Result Dhruv;
    Dhruv.set_roll_no(28);
    Dhruv.set_marks(99,98.5);
    Dhruv.display();

    return 0;
};