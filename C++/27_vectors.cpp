#include <iostream>
#include <vector>
using namespace std;

template <class T>
void display(vector<T> &v)
{

    for (int i = 0; i < v.size(); i++)
    {   
        // same thing 
        // cout << v[i] << " ";
        cout << v.at(i) << " ";
    }
    cout<<endl;
}

int main()
{
    // vector <data type> name
    // array cant be resized but vector can be resized

    vector<int> vec1;
    int size;

    cout<<"Enter the size of your vector : ";
    cin>>size;
    cout<<endl;

    for (int i = 0; i < size; i++)
    {
        int element;
        cout << "enter an element to add to this vector : " ;
        cin >> element;

        // adds the given evement in the last of vector
        vec1.push_back(element);
    }
    cout<<endl;

    // removes last evement
    vec1.pop_back();


    // display(vec1);

    // inserts 566 in the first place as iterator is starting from begaining
    vector <int> :: iterator iter = vec1.begin();
    vec1.insert(iter, 566);

    //(iterator, no of copies , value) 
    vec1.insert(iter+2,5, 566);

    display(vec1);

    return 0;
}