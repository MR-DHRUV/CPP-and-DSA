#include <iostream>
// header files
//  system defined👆 and user defined👇
// #include <o1_header.h>

using namespace std;

int globalVar = 8;

int main(int argc, char const *argv[])
{
    // Data types in c++
    int a = 4;
    float pi = 3.14;
    char c = 'c';
    int in1;
    int in2;
    bool myBool = 1; // ture <--> 1

    string mystr = "Dhruv";
    short no = 19;
    long no1 = 894894;
    float myfloat = 3.1432;
    double myDubble = 3.143212233;

    float const myconst = 9;


    //declareation of float and long
    float f = 34.4f;
    long double ld= 34.4l;

    cout<<f<<' '<<ld<<endl; 
    cout<<"Size of 34.4f is "<<sizeof(34.4f)<<endl;
    cout<<"Size of 34.4l is "<<sizeof(34.4l)<<endl;
    cout<<"Size of 34.4 is "<<sizeof(34.4)<<endl;//by deafult doubble hota haii 

    cout<<"My name is :"<<mystr<<endl;
    cout << "The value of pi with more precision is " << myDubble << "\n";
    cout << "The value of a is " << a << endl<< "The value of pi is " << pi << endl;
    // endl \n ka kaam karta hai.

    cout << "The char c is " << c << endl;
    cout << "The golbal var is " << globalVar << endl;
    cout << "The bool is " << myBool << endl;
    // << is icalled insertion operator
    // >> is is called extraction operator
    cout << "Enter Num 1 :" << endl;
    cin >> in1;

    cout << "Enter Num 2 :" << endl;
    cin >> in2;

    cout << "Sum is " << (in1 + in2) << endl;
    cout<<"A == B "<<(a==in1)<<endl;

    //////////////////////////// Type Casting  ///////////////////////////////////

    int myInt = 9;
    float castToInt = 9.74;
    cout<<"The typecated int is "<<(float)myInt<<endl;
    cout<<"The typecasted lfoat is "<<(int)castToInt<<endl;// returns integer part of float

    cout<<"The sum of a+b "<<myInt+castToInt<<endl;
    cout<<"The sum of a + intb "<<myInt+(int)castToInt<<endl;
    cout<<"The sum of a + intb "<<myInt+int(castToInt)<<endl;

    


    return 0;
}

// cpprefrence.com to find stl header files for various purposes


// by default numbers with decimal are concedered as 'doubble'