#include <iostream>
#include <list>

using namespace std;

void listprinter(list<int> &lst)
{

    list<int>::iterator iter;
    iter = lst.begin();

    cout << " ";
    for (int i = 0; i < lst.size(); i++)
    {
        cout << (*iter) << " ";
        iter++;
    };

    cout << endl;
}

int main()
{
    // list or linked-list is bi directional and is very efficient in performing insertion and deletion operations

    // list is in a contiqueous memory location  , that is ek ke baad ek hote hain elements

    // A -> B -> C...
    // to delete B
    // A -> C....

    // yehi agar array me karte toh ek ke baad ek lements ko shift karna padta

    list<int> myList; // list of 0 lenngth

    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(25);
    myList.push_back(6);
    myList.push_back(7);
    myList.push_back(3);
    myList.push_back(0);

    list<int>::iterator itr;

    itr = myList.begin();

    // *iter will point to first element of list
    cout << *itr << endl;

    listprinter(myList);

    myList.pop_back();
    listprinter(myList);

    myList.pop_front();
    listprinter(myList);

    // sorting a list
    myList.sort(); // it sorts in assending order
    listprinter(myList);

    ///////////////////////////////////////////////////// Another method ///////////////////////////
    list<int> myList1(3);

    list<int>::iterator itr1;
    itr1 = myList1.begin();

    *itr1 = 45;
    itr1++;
    *itr1 = 4;
    itr1++;
    *itr1 = 5;
    itr1++;

    listprinter(myList1);

    // merging lists
    myList.merge(myList1);
    listprinter(myList);

    // reversing
    myList.reverse();
    listprinter(myList);

    return 0;
}