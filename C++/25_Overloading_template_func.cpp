#include <iostream>
using namespace std;

template <class T>
class Harry
{
public:
    T data;

    Harry(T a) : data(a){};
    void display(void);
};

// syntax for wrriting member functions of classes having template 
template <class T>
void Harry<T> :: display()
{
    cout << data << endl;
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void func(T a){
    cout<<"I am templatizes first func "<<a<<endl;
};

void func(int a){
    cout<<"I am first func "<<a<<endl;
};



template<class T>
void func1(T a){
    cout<<"I am templatizes first func 1 "<<a<<endl;
};
// which will be called when func will be called with T = int



int main()
{
    Harry<int> a(3);
    a.display();

    func(3); // exact match takes highest priority
    // thus hardcoded int will be called 

    func1(1.2);

    return 0;
}