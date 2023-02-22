#include <iostream>
#include <map>

using namespace std;

int main()
{
    // maps store key-value pairs

    map<string, int> marks;

    marks["A"] = 98;
    marks["B"] = 80;
    marks["C"] = 91; 

    map<string, int>::iterator itr;

    //                        jab tak marks khatam ni hota tab tak ki range haii
    for (itr = marks.begin(); itr != marks.end(); itr++)
    {
        cout << (*itr).first << " " << (*itr).second << endl;
        // first gives key while second returns value
    }
    cout<<"The size of map is : "<<marks.size()<<endl;
    cout<<"map is empty : "<<marks.empty()<<endl;

    return 0;
}